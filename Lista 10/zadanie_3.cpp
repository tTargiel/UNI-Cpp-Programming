#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Tomasz Targiel
// Lista 10
// Zadanie 3

int zliczajD(string x)
{
    return (x.find("DOPISZ") != string::npos) == 1;
}

int zliczajU(string x)
{
    return (x.find("USUN") != string::npos) == 1;
}

int main()
{
    // Zadanie 4.1 z matury z informatyki
    fstream plik;
    plik.open("przyklad.txt");

    string aktualnyWiersz;
    vector<string> polecenia;

    if (plik.good())
    {
        while (!plik.eof())
        {
            getline(plik, aktualnyWiersz);
            polecenia.push_back(aktualnyWiersz);
        }
    }
    plik.close();

    int dopisz = count_if(polecenia.begin(), polecenia.end(), zliczajD);
    int usun = count_if(polecenia.begin(), polecenia.end(), zliczajU);
    int dlugoscNapisu = dopisz - usun;

    cout << "Całkowita długość napisu: " << dlugoscNapisu << endl;

    // Zadanie 4.4 z matury z informatyki
    string wyraz;

    // for (int i = 0; i < polecenia.size(); i++)
    // {
    //     cout << polecenia[i] << endl;
    //     cout << polecenia[i].size() << endl;
    // }

    for (int i = 0; i < polecenia.size(); i++)
    {
        if (int poz = polecenia[i].find("DOPISZ") != string::npos)
        {
            // cout << poz << endl;

            wyraz += polecenia[i][polecenia[i].size() - 2];
        }
        else if (polecenia[i].find("USUN") != string::npos)
        {
            wyraz.pop_back();
        }
        else if (polecenia[i].find("ZMIEN") != string::npos)
        {
            wyraz[wyraz.size() - 1] = polecenia[i][polecenia[i].size() - 2];
        }
        else if (polecenia[i].find("PRZESUN") != string::npos)
        {
            int index = wyraz.find(polecenia[i][polecenia[i].size() - 2]);
            char znak = wyraz[index];
            int kodASCII = static_cast<int>(wyraz[index]);

            if (kodASCII == 90)
            {
                wyraz[index] = static_cast<char>(65);
            }
            else
            {
                wyraz[index] = static_cast<char>(kodASCII + 1);
            }
        }
    }
    cout << wyraz << endl;

    return 0;
}
