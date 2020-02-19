//Rathinavel Sankaralingam
//Feb 18, 2020

//Move Zeros To End
#include <iostream>
#include <vector>

using namespace std;


void print(std::vector<int> &arr)
{
  for(int i=0; i<arr.size(); i++)
  {
    std::cout << arr[i] << "\t";
  }
}


void runMoveZeroToEnd()
{
  vector<int> arr = {3,0,5,1,0,7,2,8,9,6,0};
  int count = 0;
  int zeroCount = 0;
  for(int i=0; i<arr.size(); i++)
  {
    if(arr[i]!=0)
    {
      arr[count++] = arr[i];
    }
    else
      zeroCount++;
  }

  for(int i = arr.size()-1; i>=arr.size()-zeroCount; i--)
    arr[i] = 0;

  print (arr);

  
}