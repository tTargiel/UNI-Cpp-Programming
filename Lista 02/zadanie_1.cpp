#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 2
// Zadanie 1

int suma(const int tab[], unsigned size)
{
    int suma = 0;
    for (int i = 0; i < size; i++)
    {
        suma += tab[i];
    }
    return suma;
}

void suma(const int tab[], unsigned size, int *result)
{
    for (int i = 0; i < size; i++)
    {
        *result += tab[i];
    }
    cout << "1.b.: " << *result << endl;
}

void pisz(const int *tab, size_t size, ostream &out)
{
    out << "1.c.: ";
    for (int i = 0; i < size; i++)
    {
        out << tab[i] << " ";
    }
    out << endl;
}

void iota(int tab[], unsigned size)
{
    cout << "1.d.: ";
    for (int i = 0; i <= size - 1; i++)
    {
        tab[i] = i;
        cout << tab[i] << " ";
    }
    cout << endl;
}

void reverse(int *tab, size_t size)
{
    cout << "1.e.: ";
    int reverse[size];
    for (int i = size - 1, j = 0; i >= 0; i--, j++)
    {
        reverse[j] = tab[i];
        cout << reverse[j] << " ";
    }
    cout << endl;
}

int dot_product(const int *tab1, const int *tab2, size_t size)
{
    int dot_product[size];
    for (int i = 0; i < size; i++)
    {
        dot_product[i] = tab1[i] * tab2[i];
        cout << dot_product[i] << " ";
    }
    return dot_product[size];
}

int main()
{
    int tab[10] = {2, 0, 0, 5, 0, 4, 2, 1, 3, 7};
    const int size = 6;
    int result = 0;
    ostream &out = cout;
    int tablica[size];
    int tab1[4] = {1, 3, 3, 7};
    int tab2[4] = {8, 0, 0, 8};
    cout << "1.a.: " << suma(tab, size) << endl;
    suma(tab, size, &result);
    pisz(tab, size, out);
    iota(tablica, size);
    reverse(tab, size);
    cout << "1.f.: ";
    dot_product(tab1, tab2, size);
    return 0;
}
