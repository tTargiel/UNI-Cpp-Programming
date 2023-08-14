#include <iostream>
#include <cmath>

using namespace std;

// Tomasz Targiel
// Lista 4
// Zadanie 2

double find_root(double (*f)(double), double a, double b, double tolerance = 1e-6)
{
    if (f(a) * f(b) > 0)
    {
        cout << "Funkcja nie posiada miejsc zerowych w podanym przedziale" << endl;
    }
    while (abs(a - b) > tolerance)
    {
        double x1 = (a + b) / 2;
        if (abs(f(x1)) <= tolerance)
        {
            return x1;
        }
        else if (f(x1) * f(a) < 0)
        {
            b = x1;
        }
        else
        {
            a = x1;
        }
    }
    return 0;
}

double f(double x)
{
    return cos(x) - x;
}

double f2(double x)
{
    return cos(x) - 0.5;
}

int main()
{
    double a = 0;
    double b = 2;
    cout << "a. cos(x) = x w przedziale [0, 2], m.zer: " << find_root(f, a, b) << endl;
    a = 0;
    b = 1.5;
    cout << "b. cos(x) = 1/2 w przedziale [0, 1.5], m.zer: " << find_root(f2, a, b) << endl;
    return 0;
}
