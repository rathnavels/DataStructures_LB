//Rathinavel Sankaralingam
//Feb 20, 2020

// Iterative Merge Sort

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(std::vector<int> &arr);
void mergeArr(vector<int> left, vector<int> right, vector<int> &arr, int K);

void runIterativeMergeSort()
{
  std::vector<int> arr = {3,5,1,19,12,7,2,8,9,6,41};

  int mid = arr.size()/2;
  int N = arr.size();
  int currSize;

  for(currSize = 1; currSize < N; currSize = currSize * 2)
  {
    
    for(int leftStart = 0; leftStart < N-1; leftStart += 2*currSize)
    {
      int to = std::min(leftStart + (2*currSize)-1, N-1);
      int mid = std::min((leftStart + currSize-1), N-1);
      vector<int> leftArray, rightArray;
      leftArray.insert(leftArray.begin(),arr.begin()+leftStart,arr.begin()+mid+1);
      rightArray.insert(rightArray.begin(),arr.begin()+mid+1,arr.begin()+to+1);
      mergeArr(leftArray,rightArray,arr,leftStart);
    }
  }
  print(arr);
}

void mergeArr(vector<int> left, vector<int> right, vector<int> &arr, int K)
{
  int i, j, k;
  i = 0;
  j = 0;
  k = K;

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