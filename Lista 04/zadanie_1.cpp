#include <iostream>
#include <vector>

using namespace std;

// Tomasz Targiel
// Lista 4
// Zadanie 1

double operator*(vector<double> v, vector<double> w)
{
    double dotProd = 0;
    for (int i = 0; i <= v.size(); i++)
    {
        dotProd += v[i] * w[i];
    }
    return dotProd;
}

int main()
{
    vector<double> v = {1.1, 2.1, 3.1, 4.1};
    vector<double> w = {5.2, 6.2, 7.2, 8.2};
    cout << "Iloczyn skalarny wektorów (v*w): " << v * w << endl;
    return 0;
}
