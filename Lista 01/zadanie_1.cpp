#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 1
// Zadanie 1

int main()
{
    for (int n = 0; n <= 40; n++)
    {
        int j = 1; // By uzyskać silnie dużych wyrazów (od 13! wypadałoby zastosować long int lub long long int (są to typy zmiennych o zdecydowanie większej pojemności)
        for (int i = 1; i <= n; i++)
        {
            j = j * i;
        }
        cout << n << "!: " << j << endl;
    }
    return 0;
}
