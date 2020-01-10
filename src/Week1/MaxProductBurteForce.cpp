//Rathinavel Sankaralingam
//Jan 10, 2020

// Find maximum Product of two integers in an array
// Input : -10, -3, 5, 6, -2
// output : -10 and -3

#include <iostream>
#include <vector>
#include <algorithm>

void runMaxProduct()
{
  std::vector<int> arr = {-10, -3, 5, 6, -2};
  
  int maxProduct = 0;
  for(int i=0; i<arr.size()-1; i++)
  {
    for(int j=i+1; j<arr.size(); j++)
      maxProduct = std::max(maxProduct , arr[j]*arr[i]);
  }
  std::cout << maxProduct;
}