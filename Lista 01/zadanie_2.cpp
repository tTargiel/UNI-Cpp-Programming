#include <iostream>
#include <cmath>

using namespace std;

// Tomasz Targiel
// Lista 1
// Zadanie 2

const int n = 1000000;

void a()
{
    double wynikA = 0;
    for (int j = 1; j <= n; j++)
    {
        wynikA += (pow(-1, j + 1)) / (2 * j - 1);
    }
    cout << "A)" << endl;
    cout << 4 * wynikA << "\n\n";
}

void b()
{
    double wynikB = 1;
    for (int j = 1; j <= n; j++)
    {
        wynikB *= (4 * pow(j, 2)) / (4 * pow(j, 2) - 1);
    }
    cout << "B)" << endl;
    cout << 2 * wynikB << "\n\n";
}

void c()
{
    double wynikC = 0;
    for (int j = 1; j <= n; j++)
    {
        wynikC += (1) / (pow(2 * j - 1, 2));
    }
    cout << "C)" << endl;
    cout << sqrt(8 * wynikC) << "\n\n";
}

int main()
{
    a();
    b();
    c();
    return 0;
}
