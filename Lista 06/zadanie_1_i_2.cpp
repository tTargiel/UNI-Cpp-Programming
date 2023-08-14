#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Tomasz Targiel
// Lista 6

class Fraction
{
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
    int64_t n, d;

public:
    Fraction(int n, int d = 1) : n(n / gcd(n, d)), d(d / gcd(n, d)) {}
    int64_t num() const { return n; }
    int64_t den() const { return d; }
    double to_double() const { return n / (static_cast<double>(d)); }
    Fraction &operator*=(const Fraction &rhs)
    {
        int new_n = n * rhs.n / gcd(n * rhs.n, d * rhs.d);
        d = d * rhs.d / gcd(n * rhs.n, d * rhs.d);
        n = new_n;
        return *this;
    }
    Fraction &operator+=(const Fraction &rhs)
    {
        bool run = true;
        int max = (d > rhs.d) ? d : rhs.d;

        while (run)
        {
            if (max % d == 0 && max % rhs.d == 0)
            {
                run = false;
            }
            else
                max++;
        };

        int new_n = (max / d) * n + (max / rhs.d) * rhs.n;
        d = max;
        n = new_n;
        return *this;
    }
    Fraction &operator-=(const Fraction &rhs)
    {
        bool run = true;
        int max = (d > rhs.d) ? d : rhs.d;

        while (run)
        {
            if (max % d == 0 && max % rhs.d == 0)
            {
                run = false;
            }
            else
                max++;
        };

        int new_n = (max / d) * n - (max / rhs.d) * rhs.n;
        d = max;
        n = new_n;
        return *this;
    }
    Fraction &operator/=(const Fraction &rhs)
    {
        int new_n = (n * rhs.d) / gcd(n * rhs.d, d * rhs.n);
        d = (d * rhs.n) / gcd(n * rhs.d, d * rhs.n);
        n = new_n;
        return *this;
    }
};
ostream &operator<<(ostream &out, const Fraction &f)
{
    return out << f.num() << '/' << f.den();
}
bool operator==(const Fraction &lhs, const Fraction &rhs)
{
    return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}
bool operator!=(const Fraction &lhs, const Fraction &rhs)
{
    return !(lhs == rhs);
}
Fraction operator*(Fraction lhs, const Fraction &rhs)
{
    return lhs *= rhs;
}
Fraction operator+(Fraction lhs, const Fraction &rhs)
{
    return lhs += rhs;
}
Fraction operator-(Fraction lhs, const Fraction &rhs)
{
    return lhs -= rhs;
}
Fraction operator/(Fraction lhs, const Fraction &rhs)
{
    return (lhs /= rhs);
}
Fraction f(int n, double x)
{
    vector<int> t;
    double a = floor(x);
    t.push_back(static_cast<int>(a));
    while (n > 0)
    {
        x = 1 / (x - a);
        a = floor(x);
        t.push_back(static_cast<int>(a));
        n--;
    }
    Fraction s(t.back(), 1);
    if (t.size() > 1)
    {
        for (int i = t.size() - 2; i >= 0; i--)
        {
            Fraction tmp(s.den(), s.num());
            int64_t den = t[i] * tmp.den() + tmp.num();
            s = Fraction(den, tmp.den());
        }
    }
    cout << s << "\t" << s.to_double();
    return s;
}

int main()
{
    cout << "Zadanie 1" << endl;
    cout << "a)" << endl;
    Fraction f1(3, 8), f2(1, 2), f3(10, 2);
    cout << f1 << " * " << f2 << " = " << f1 * f2 << '\n'
         << f1 << " + " << f2 << " = " << f1 + f2 << '\n'
         << f1 << " - " << f2 << " = " << f1 - f2 << '\n'
         << f1 << " : " << f2 << " = " << f1 / f2 << '\n';

    cout << "\nb)" << endl;
    cout << "i." << endl;
    Fraction result_i(0, 1);
    for (int i = 1; i <= 10; i++)
    {
        Fraction a(1, i * (i + 1));
        result_i += a;
        cout << result_i << "\t" << result_i.to_double() << "\n";
    }

    cout << "\nii." << endl;
    Fraction result_ii(0, 1);
    for (int i = 1; i <= 20; i++)
    {
        Fraction b(pow(-1, i + 1), i);
        result_ii += b;
        cout << result_ii << "\t" << result_ii.to_double() << "\n";
    }

    cout << "\niii." << endl;
    Fraction result_iii(0, 1);
    for (int i = 1; i <= 15; i++)
    {
        Fraction c(1, pow(2, i) * i);
        result_iii += c;
        cout << result_iii << "\t" << result_iii.to_double() << "\n";
    }

    cout << "\nZadanie 2" << endl;
    cout << "a)" << endl;
    for (int i = 0; i < 10; i++)
    {
        f(i, (sqrt(5) + 1) / 2.0);
        cout << endl;
    }

    cout << "\nb)" << endl;
    for (int i = 0; i < 10; i++)
    {
        f(i, exp(1));
        cout << endl;
    }

    cout << "\nc)" << endl;
    for (int i = 0; i < 10; i++)
    {
        f(i, 3.1415926535);
        cout << endl;
    }
}
