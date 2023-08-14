#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Tomasz Targiel
// Lista 1
// Zadanie 3

const double t0 = 1 / (sqrt(3));

void a()
{
    double ti = t0;
    cout << "A)" << endl;
    for (int i = 0; i <= 30; i++)
    {
        ti = (sqrt(pow(ti, 2) + 1) - 1) / ti;
        double pi = 6 * pow(2, i + 1) * ti;
        cout << "dla i=" << i << ": " << pi << endl;
    }
    cout << endl;
}

void b()
{
    double ti = t0;
    cout << "B)" << endl;
    for (int i = 0; i <= 30; i++)
    {
        ti = ti / (sqrt(pow(ti, 2) + 1) + 1);
        double pi = 6 * pow(2, i + 1) * ti;
        cout << "dla i=" << i << ": " << pi << endl;
    }
    cout << endl;
}

int main()
{
    cout << setprecision(30) << fixed; // Ustawiam dokładność wyświetlanych wyników na 20 miejsc po przecinku
    a();                               // Dla tej metody błąd pomniejszał się od i=0 aż do i=17, później wzrastał
    b();                               // Dla tej metody błąd konsekwentnie się pomniejszał aż do ostatniego wyrazu
    return 0;
}
