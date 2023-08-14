#include "image.h"

#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

void Image::load(const string &filename)
{
    constexpr auto MAGIC = "P6";

    this->filename = filename;

    ifstream in(filename, ios::binary);
    if (!in)
        throw invalid_argument("failed to open \"" + filename + "\"");

    in >> magic;

    if (magic != MAGIC)
        throw logic_error("unknown magic number " + magic);

    in >> my_width >> my_height >> color_depth;

    if (my_width <= 0 || my_width > 10000 || my_height <= 0 || my_height > 10000 || color_depth <= 0 || color_depth > 255)
        throw logic_error("invalid image parameter(s): " + to_string(my_width) + " " + to_string(my_height) + " " + to_string(color_depth));

    in.ignore(1);
    pixels.resize(my_height);
    for (auto &line : pixels)
    {
        line.resize(my_width);
        in.read(reinterpret_cast<char *>(&line[0]), my_width * sizeof(RGB));
        if (!in)
            throw logic_error("failed to read binary pixel data from file " + filename);
    }
}

void Image::save_as(const string &filename)
{
    ofstream out(filename, ios::binary);
    if (!out)
        throw invalid_argument("failed to save \"" + filename + "\"");

    out << magic << endl;
    out << my_width << " " << my_height << endl;
    out << color_depth << endl;

    pixels.resize(my_height);
    for (auto &line : pixels)
    {
        line.resize(my_width);
        out.write(reinterpret_cast<char *>(&line[0]), my_width * sizeof(RGB));
        if (!out)
            throw logic_error("failed to write binary pixel data to file " + filename);
    }
}

void Image::add_watermark()
{
    for (int i = my_height * 0.2; i <= my_height * 0.8; i++)
    {
        for (int j = my_width * 0.1; j <= my_width * 0.15; j++)
        {
            pixels[i][j].red = int(floor((i / float(my_height)) * 255));
            pixels[i][j].blue = int(sqrt(floor((i * j / float(my_height * my_width)) * 255)));
        }
    }
}

void Image::blurr()
{
    for (int loop = 0; loop < 100; loop++)
    {
        for (int i = 1; i < my_height - 1; i++)
        {
            for (int j = 1; j < my_width - 1; j++)
            {
                pixels[i][j].red = (pixels[i - 1][j - 1].red + pixels[i - 1][j].red + pixels[i - 1][j + 1].red + pixels[i][j - 1].red + pixels[i][j + 1].red + pixels[i + 1][j - 1].red + pixels[i + 1][j].red + pixels[i + 1][j + 1].red) / 8;
                pixels[i][j].green = (pixels[i - 1][j - 1].green + pixels[i - 1][j].green + pixels[i - 1][j + 1].green + pixels[i][j - 1].green + pixels[i][j + 1].green + pixels[i + 1][j - 1].green + pixels[i + 1][j].green + pixels[i + 1][j + 1].green) / 8;
                pixels[i][j].blue = (pixels[i - 1][j - 1].blue + pixels[i - 1][j].blue + pixels[i - 1][j + 1].blue + pixels[i][j - 1].blue + pixels[i][j + 1].blue + pixels[i + 1][j - 1].blue + pixels[i + 1][j].blue + pixels[i + 1][j + 1].blue) / 8;
            }
        }
    }
}

void Image::extract_layer(ColorLayer color_layer)
{
    switch (color_layer)
    {
    case ColorLayer::Red:
        for (int i = 0; i < my_height; i++)
        {
            for (int j = 0; j < my_width - 1; j++)
            {
                pixels[i][j].green = 0;
                pixels[i][j].blue = 0;
            }
        }
        break;
    case ColorLayer::Green:
        for (int i = 0; i < my_height; i++)
        {
            for (int j = 0; j < my_width; j++)
            {
                pixels[i][j].red = 0;
                pixels[i][j].blue = 0;
            }
        }
        break;
    case ColorLayer::Blue:
        for (int i = 0; i < my_height; i++)
        {
            for (int j = 0; j < my_width; j++)
            {
                pixels[i][j].red = 0;
                pixels[i][j].green = 0;
            }
        }
        break;
    }
}

void Image::filter()
{
    for (int i = 1; i < my_height - 1; i++)
    {
        for (int j = 1; j < my_width - 1; j++)
        {
            pixels[i][j].red = abs(pixels[i][j].red - pixels[i + 1][j + 1].red);
            pixels[i][j].green = abs(pixels[i][j].green - pixels[i + 1][j + 1].green);
            pixels[i][j].blue = abs(pixels[i][j].blue - pixels[i + 1][j + 1].blue);
        }
    }
}

void Image::flip_horizontally()
{
    for (int i = 0; i < my_height - 1; i++)
    {
        for (int j = 0; j < (my_width - 1) / 2; j++)
        {
            swap(pixels[i][j], pixels[i][my_width - 1 - j]);
        }
    }
}

void Image::flip_vertically()
{
    for (int i = 0; i < (my_height - 1) / 2; i++)
    {
        for (int j = 0; j < my_width - 1; j++)
        {
            swap(pixels[i][j], pixels[my_height - 1 - i][j]);
        }
    }
}

void Image::inflate()
{
    vector<vector<RGB>> temporary_pixels;
    int double_width = my_width * 2;
    int double_height = my_height * 2;
    temporary_pixels.resize(double_height);
    for (int i = 0; i < double_height; i++)
    {
        temporary_pixels[i].resize(double_width);
    }
    int x = 0;
    int y = 0;
    for (int i = 0; i < double_height; i += 2)
    {
        for (int j = 0; j < double_width; j += 2)
        {
            temporary_pixels[i][j] = pixels[y][x];
            temporary_pixels[i][j + 1] = pixels[y][x];
            temporary_pixels[i + 1][j] = pixels[y][x];
            temporary_pixels[i + 1][j + 1] = pixels[y][x];
            x += 1;
        }
        y += 1;
        x = 0;
    }
    pixels.resize(double_height);
    for (int i = 0; i < double_height; i++)
    {
        pixels[i].resize(double_width);
    }
    for (int i = 0; i < double_height; i++)
    {
        for (int j = 0; j < double_width; j++)
        {
            pixels[i][j] = temporary_pixels[i][j];
        }
    }
    my_width *= 2;
    my_height *= 2;
}

void Image::negative()
{
    for (int i = 0; i < my_height - 1; i++)
    {
        for (int j = 0; j < my_width - 1; j++)
        {
            pixels[i][j].red = 255 - pixels[i][j].red;
            pixels[i][j].green = 255 - pixels[i][j].green;
            pixels[i][j].blue = 255 - pixels[i][j].blue;
        }
    }
}

void Image::rotate_clockwise_90()
{
    vector<vector<RGB>> temporary_pixels;
    int new_width = my_height;
    int new_height = my_width;
    temporary_pixels.resize(new_height);
    for (int i = 0; i < new_height; i++)
    {
        temporary_pixels[i].resize(new_width);
    }
    for (int i = 0; i < new_height; i++)
    {
        for (int j = 0; j < new_width; j++)
        {
            temporary_pixels[i][j] = pixels[my_height - 1 - j][i];
        }
    }
    pixels.resize(new_height);
    for (int i = 0; i < new_height; i++)
    {
        pixels[i].resize(new_width);
    }
    for (int i = 0; i < new_height; i++)
    {
        for (int j = 0; j < new_width; j++)
        {
            pixels[i][j] = temporary_pixels[i][j];
        }
    }
    my_height = new_height;
    my_width = new_width;
}

void Image::sepia()
{
    for (int i = 0; i < my_height - 1; i++)
    {
        for (int j = 0; j < my_width - 1; j++)
        {
            int meanRed, meanGreen, meanBlue;
            int W = 30;
            int mean = round((pixels[i][j].red + pixels[i][j].green + pixels[i][j].blue) / 3);
            if (mean + 2 * W >= 255)
            {
                meanRed = 255;
            }
            else
            {
                meanRed = mean + 2 * W;
            }
            if (mean + W >= 255)
            {
                meanGreen = 255;
            }
            else
            {
                meanGreen = mean + W;
            }
            if (mean >= 255)
            {
                meanBlue = 255;
            }
            else
            {
                meanBlue = mean;
            }
            pixels[i][j].red = meanRed;
            pixels[i][j].green = meanGreen;
            pixels[i][j].blue = meanBlue;
        }
    }
}

void Image::shrink()
{
    vector<vector<RGB>> temporary_pixels;
    int half_width = my_width / 2;
    int half_height = my_height / 2;
    temporary_pixels.resize(half_height);
    for (int i = 0; i < half_height; i++)
    {
        temporary_pixels[i].resize(half_width);
    }
    int x = 0;
    int y = 0;
    for (int i = 0; i < my_height - 1; i += 2)
    {
        for (int j = 0; j < my_width - 1; j += 2)
        {
            temporary_pixels[y][x].red = round((pixels[i][j].red + pixels[i][j + 1].red + pixels[i + 1][j].red + pixels[i + 1][j + 1].red) / 4);
            temporary_pixels[y][x].green = round((pixels[i][j].green + pixels[i][j + 1].green + pixels[i + 1][j].green + pixels[i + 1][j + 1].green) / 4);
            temporary_pixels[y][x].blue = round((pixels[i][j].blue + pixels[i][j + 1].blue + pixels[i + 1][j].blue + pixels[i + 1][j + 1].blue) / 4);
            x += 1;
        }
        y += 1;
        x = 0;
    }
    pixels.resize(half_height);
    for (int i = 0; i < half_height; i++)
    {
        pixels[i].resize(half_width);
    }
    for (int i = 0; i < half_height; i++)
    {
        for (int j = 0; j < half_width; j++)
        {
            pixels[i][j] = temporary_pixels[i][j];
        }
    }
    my_width /= 2;
    my_height /= 2;
}

void Image::to_grayscale()
{
    for (int i = 0; i < my_height - 1; i++)
    {
        for (int j = 0; j < my_width - 1; j++)
        {
            int mean = round((pixels[i][j].red + pixels[i][j].green + pixels[i][j].blue) / 3);
            pixels[i][j].red = pixels[i][j].green = pixels[i][j].blue = mean;
        }
    }
}

int Image::height() const
{
    return my_height;
}

int Image::width() const
{
    return my_width;
}
