//Rathinavel Sankaralingam
//Jan 10, 2020

// Print the number of bits
// a. Input : 11
// Output : 4 ( Since it has 4 bits)
// 
// 
// b. Input : 32
// Output : 6 (Since it has 6 bits)

#include <iostream>

void runNumBits()
{
  int k = 32;
  int count = 0;
  while(k > 0)
  {
    count++;
    k = k >> 1;
  }

  std::cout << count;
}

int countBits(int k)
{
  int count = 0;
  while(k > 0)
  {
    count++;
    k = k >> 1;
  }

  return count;
}