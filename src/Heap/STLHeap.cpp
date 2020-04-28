//Rathinavel Sankaralingam
//Apr 24, 2020


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void runSTLHeap()
{
  vector<int> arr = {0,1,2,3,4,5,6,7,8,9};
  std::make_heap(arr.begin(),arr.end());

  for (int number : arr)
  {
    std::cout << number << "\t";
  }

  //arr[5] = 23;

  cout << std::is_heap(arr.begin(),arr.end()) ? "True" : "False";
}