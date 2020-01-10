//Rathinavel Sankaralingam
//Jan 10, 2020


#include <iostream>
#include <vector>
#include <unordered_set>

// Print Duplicates numbers in an array.
// Given Range : 0 to 10.
// Input : 1,2,2,2,2,4,5,7,8,8
// Output : 2, 8

// Complexity O(n)

void runPrintDuplicate()
{
  std::vector<int> arr = {1,2,0,2,2,2,4,5,7,8,8,2,2,3,6,7,3,0,1};

  std::unordered_set<int> dupeArr;
  
  for(int i=0; i<arr.size(); i++)
  {
    int val = arr[i];
    if(arr[abs(val)] > 0)
      arr[abs(val)] *= -1;
    else
      dupeArr.insert(abs(val));
  }

  for(int i:dupeArr)
  {
    std::cout << i << " ";
  } 
  
}