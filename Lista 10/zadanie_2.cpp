#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// Tomasz Targiel
// Lista 10
// Zadanie 2

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

int pot2(int x)
{
    return x * x;
}

int losowa()
{
    return rand() % 16;
}

int main()
{
    srand(time(NULL));

    vector<int> wektorPierwszy(10);
    vector<int> wektorDrugi(10);

    iota(wektorPierwszy.begin(), wektorPierwszy.end(), 0);
    cout << wektorPierwszy;

    int suma = accumulate(wektorPierwszy.begin(), wektorPierwszy.end(), 0);
    cout << "Suma: " << suma << endl;

    transform(wektorPierwszy.begin(), wektorPierwszy.end(), wektorPierwszy.begin(), pot2);
    cout << wektorPierwszy;

    generate(wektorDrugi.begin(), wektorDrugi.end(), losowa);
    cout << wektorDrugi;

    int max = *max_element(wektorDrugi.begin(), wektorDrugi.end());
    cout << "Max = " << max << endl;

    sort(wektorDrugi.begin(), wektorDrugi.end());
    cout << wektorDrugi;

    unique(wektorDrugi.begin(), wektorDrugi.end());
    cout << wektorDrugi;

    sort(wektorDrugi.begin(), wektorDrugi.end());
    wektorDrugi.erase(unique(wektorDrugi.begin(), wektorDrugi.end()), wektorDrugi.end());
    cout << wektorDrugi;

    vector<int> wektorTrzeci;
    set_intersection(wektorPierwszy.begin(), wektorPierwszy.end(), wektorDrugi.begin(), wektorDrugi.end(), back_inserter(wektorTrzeci));
    cout << wektorTrzeci;

    return 0;
}
