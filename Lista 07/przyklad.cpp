#include <iostream>
#include <vector>
#include <algorithm> // count_if, sort

struct Zliczaj_5
{
    bool operator()(int k) const { return k == 5; }
};

int main()
{
    std::vector<int> v = {1, 5, 16, 12, 35, 6, 13, 45, 5, 8};
    std::cout << std::count_if(begin(v), end(v), Zliczaj_5()) << "\n";
    std::cout << std::count_if(begin(v), end(v), [](int k) { return k == 5; }) << "\n";
}
