// Rathinavel Sankaralingam
// Jan 10, 2020

#include <vector>
#include <iostream>

void runSubArrayZeroBruteForce()
{
  std::vector<int> arr = {54,46,100,-200};

  int sum = 0;
  bool SUMZERO = false;

  for(int i=0; i<arr.size()-1; i++)
  {
  sum = arr[i];

    for(int j=i+1; j<arr.size(); j++)
    {
      sum += arr[j];
      if(sum == 0)
      {
        SUMZERO = true;
        break;
      }
    }
  }

  if(SUMZERO)
  std::cout << "Yes there is";
  else
    std::cout << "No there is not";
}
