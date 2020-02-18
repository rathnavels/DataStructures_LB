//Rathinavel Sankaralingam
//Feb 18, 2020


// Recursive Bubble Sort

#include <iostream>
#include <string>

void bubblesort(int arr[], int n);
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void print(int arr[])
{
  for(int i=0; i<8; i++)
  {
    std::cout << arr[i] << "\t";
  }
}

void runRecursiveBubbleSort()
{
  int arr[] ={3,5,1,7,2,8,9,6};
  bubblesort(arr,8);
  print(arr);
}

void bubblesort(int arr[], int n)
{
  if(n==1)
    return;

  for(int i=0; i<n-1; i++)
    if(arr[i]>arr[i+1])
      swap(arr[i],arr[i+1]);

  bubblesort(arr,--n);
}