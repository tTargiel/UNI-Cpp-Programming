#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 4
// Zadanie 3

int main(int argc, char *argv[])
{
    double suma = 0;
    for (int i = 1; i != argc; i++)
    {
        string arg = argv[i];
        double n;
        if ((arg == "-h") || (arg == "--help"))
        {
            cout << "Pomoc" << endl;
            return 0;
        }
        else if (sscanf(argv[i], "%la", &n) == 1)
        {
            suma += stod(argv[i]);
        }
        else
        {
            cerr << "Podano niepoprawne argumenty" << endl;
            return 0;
        }
    }
    cout << suma << endl;
    return 0;
}
