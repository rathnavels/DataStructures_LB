//Rathinavel Sankaralingam
//April 3, 2020


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void runLargestSumSubArray()
{
  vector<int> arr = {-2,3,-1,4,-7,2,3,1,0,-2,7,2,-4};

  int hithertoMax = arr[0];
  int runningMax = arr[0];

  for (int i = 1; i < arr.size(); i++)
  {
    runningMax = max(arr[i],runningMax+arr[i]);
    hithertoMax = max(runningMax,hithertoMax);
  }

  std::cout << hithertoMax;
}