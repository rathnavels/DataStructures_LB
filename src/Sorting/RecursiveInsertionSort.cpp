#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> &arr);

void runRecursive(vector<int> &arr, int i);

void runRecursiveInsertionSort()
{
  std::vector<int> arr = {3,7,5,1,7,2,8,9,6,24,12,16,12};
  runRecursive(arr,1);
  print(arr);
}

void runRecursive(vector<int> &arr, int i)
{
  if(i == arr.size())
    return;

  int num = arr[i];
  int j = i;
  while(j >0 && arr[j-1] > num)
  {
    arr[j] = arr[j-1];
    j--;
  }
  arr[j] = num;

  runRecursive(arr,++i);
}