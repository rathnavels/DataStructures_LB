//Rathinavel Sankaralingam
//Jan 20, 2020

// Input : 11(eleven)
// Output : 4
// 
// Explanation :
// Eleven is 1011
// Flipping bits 0100 which is four

#include <iostream>

int countNumBits(int k);

void runFlipBits()
{
  int num = 4;
  int flippedNum = 0;
  
  int count = countNumBits(num);
  
  for(int i=count-1; i>=0; i--)
  {
    int bit = (num >> i) & 1;
    flippedNum = (flippedNum << 1) | (bit ^ 1);
  }
  std::cout << flippedNum;
}

int countNumBits(int k)
{
  int count = 0;
  while(k > 0)
  {
    count++;
    k = k >> 1;
  }

  return count;
}