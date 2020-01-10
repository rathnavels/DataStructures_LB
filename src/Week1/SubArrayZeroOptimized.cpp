// Rathinavel Sankaralingam
// Jan 10, 2020

#include <iostream>
#include <vector>
#include <unordered_set>

void runSubArrayZeroOptimzed()
{
  std::vector<int> arr = {54,46,100,-210,-8,-4,-4};
  std::unordered_set<int> sumArray;
  int sum = 0;
  bool SUMZERO = false;
  for(int i=0; i<arr.size(); i++)
  {
    sum += arr[i];
    if(sumArray.find(sum) != sumArray.end() || sum == 0)
    {
      SUMZERO = true;
      std::cout << "Yes there is\n";
      break;
    }
    else
    {
      sumArray.insert(sum);
    } 
  }

  if(SUMZERO == false)
    std::cout << "No there is not\n";
  
}