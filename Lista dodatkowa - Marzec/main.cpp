#include <iostream>

using namespace std;

// Tomasz Targiel
// Lista dodatkowa - Marzec

int countBit1Fast(uint32_t n)
{
  n = (n & 0x55555555u) + ((n >> 1) & 0x55555555u);
  n = (n & 0x33333333u) + ((n >> 2) & 0x33333333u);
  n = (n & 0x0f0f0f0fu) + ((n >> 4) & 0x0f0f0f0fu);
  n = (n & 0x00ff00ffu) + ((n >> 8) & 0x00ff00ffu);
  n = (n & 0x0000ffffu) + ((n >> 16) & 0x0000ffffu);
  return n;
}

int main()
{
  cout << (!4);
  return 0;
}
