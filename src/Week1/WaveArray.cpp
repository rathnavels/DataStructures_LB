// Rathinavel Sankaralingam
// Jan 10, 2020

#include <iostream>
#include <vector>

void swap(int &a, int &b);

void runWave()
{
  std::vector<int> arr = {1, 3, 6, 3, 7, 8, 9, 3, 4, 7, 2, 4};
  
  for(int i=1; i<arr.size()-1; i++)
  {
    if(arr[i] >= arr[i-1])
    {
      if(arr[i+1] > arr[i])
        swap(arr[i],arr[i+1]);
    }
    else
    {
      if(arr[i+1] < arr[i])
        swap(arr[i],arr[i+1]);
    }
    
  }

  for(int i : arr)
    std::cout << i << " ";
}

void swap(int &a, int &b)
{
  int temp;
  temp = b;
  b = a;
  a = temp;
}