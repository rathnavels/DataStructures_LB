//Rathinavel Sankaralingam
//Jan 10, 2020


#include <iostream>
#include <vector>
#include <algorithm>

// Question : Minimum Sum Sub Array of size given size K
// Input : 10, 4, 1, 2, 5 , 6, 3, 8, 1, 0
// Output : Index 8 to 9 with Sum as 1
// K is 2

void runMinSizeSubArray()
{
  std::vector<int> arr = {10, 4, 1, 2, 5 , 6, 3, 8, 1, 0};
  int minSum = INT_MAX;
  int K = 2;
  int index1, index2;
  for(int i=0; i<=arr.size()-K; i++)
  {
    int sum = arr[i];
    for(int j=i+1; j<i+K; j++)
    {
      sum += arr[j];
    }
    if(sum < minSum)
    { 
      index1 = i; index2 = i+K-1;
      minSum = sum;
    }
  }
  std::cout << minSum << "\n";
  std::cout << "Index1 :" << index1 << "\t" << "Index2 :" << index2;
}