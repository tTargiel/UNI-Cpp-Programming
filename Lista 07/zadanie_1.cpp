#include <iostream>
#include <vector>
#include <algorithm> // count_if, sort

using namespace std;

// Tomasz Targiel
// Lista 7

struct Sortuj
{
    bool operator()(int a, int b) const { return a % 10 < b % 10; }
};

int main()
{
    vector<int> v = {1, 5, 16, 12, 35, 6, 13, 45, 5, 8};
    sort(begin(v), end(v), Sortuj());
    cout << "Podpunkt a)\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    cout << "\nPodpunkt b)\n";
    sort(begin(v), end(v), [](int a, int b) {
        return a % 10 < b % 10;
    });
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
