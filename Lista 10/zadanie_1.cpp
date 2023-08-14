#include <iostream>
#include <vector>

using namespace std;

// Tomasz Targiel
// Lista 10
// Zadanie 1

template <typename T>
ostream &operator<<(ostream &strumien, vector<T> &wektor)
{
    for (int i = 0; i < wektor.size(); i++)
    {
        cout << wektor[i] << " ";
    }
    cout << endl;
    return strumien;
}

int main()
{
    vector<int> wektor = {0, 1, 1, 2, 3, 5, 8, 13};
    cout << wektor;
    return 0;
}
