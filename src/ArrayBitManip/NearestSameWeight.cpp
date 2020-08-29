#include <iostream>

using namespace std;

void runNearestSameWeight()
{
  unsigned int num = 64;
  int sz = sizeof(num) * 8;

  for (int i = 0; i < sz; i++)
  {
    if (((num >> i) & 1) != ((num >> i + 1) & 1))
    {
      int x = (1 << i) + (1 << (i+1));
      num ^= x;
      break;
    }
  }

  cout << num;
}