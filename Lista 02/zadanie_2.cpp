#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista 2
// Zadanie 2

int porownaj(const void *a, const void *b)
{
    const char *aa = *(const char **)a;
    const char *bb = *(const char **)b;
    int dlugoscA = strlen(aa);
    int dlugoscB = strlen(bb);
    if (dlugoscA > dlugoscB)
        return 1;
    if (dlugoscA < dlugoscB)
        return -1;
    return strcmp(aa, bb);
}

int main()
{
    const char *tablica[] = {"duda", "morawiecki", "obajtek", "kaczyński", "ziobro", "sasin", "niedzielski", "szumowski"};
    size_t iloscWyrazow = sizeof(tablica) / sizeof *tablica;
    qsort(tablica, iloscWyrazow, sizeof(char *), porownaj);
    for (int i = 0; i < iloscWyrazow; i++)
    {
        cout << i << ": " << tablica[i] << endl;
    }
    return 0;
}
