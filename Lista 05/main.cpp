#include "image.h"
#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 5

int main()
{
    Image image;
    image.load("obrazek.ppm");
    // image.add_watermark();
    // image.blurr();
    // image.extract_layer(ColorLayer::Red);
    // image.extract_layer(ColorLayer::Green);
    // image.extract_layer(ColorLayer::Blue);
    // image.filter();
    // image.flip_horizontally();
    // image.flip_vertically();
    // image.inflate();
    // image.negative();
    // image.rotate_clockwise_90();
    // image.sepia();
    // image.shrink();
    cout << image.height() << endl;
    cout << image.width() << endl;
    image.save_as("x.ppm");
    return 0;
}
