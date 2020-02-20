//Rathinavel Sankaralingam
//Feb 20, 2020


#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> &arr);
void merge(vector<int> left, vector<int> right, vector<int> &arr);
void mergeSortHelper(vector<int> &arr);

void runMergeSort()
{
  std::vector<int> arr = {3,5,1,19,12,7,2,8,9,6,41};

  mergeSortHelper(arr);

  print(arr);
}

void mergeSortHelper(vector<int>& arr)
{
  if(arr.size() < 2)
    return;

  int mid = arr.size()/2;
  vector<int> leftArray, rightArray;
  leftArray.insert(leftArray.begin(), arr.begin(), arr.begin()+mid);
  rightArray.insert(rightArray.begin(), arr.begin()+mid, arr.end());
  
  mergeSortHelper(leftArray);
  mergeSortHelper(rightArray);
  merge(leftArray,rightArray,arr);
}

void merge(vector<int> left, vector<int> right, vector<int> &arr)
{
  int i, j, k;
  i = 0;
  j = 0;
  k = 0;

  while(i<left.size() && j < right.size())
  {
    if(left[i]<right[j])
    {
      arr[k] = left[i];
      i++;
    }
    else
    {
      arr[k] = right[j];
      j++;
    }
    k++;
  }
  while(i<left.size())
  {
    arr[k] = left[i];
    k++; i++;
  }
  while(j<right.size())
  {
    arr[k] = right[j];
    k++; j++;
  }
}