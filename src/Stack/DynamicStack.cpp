//Rathinavel Sankaralingam
//Mar 21, 2020


#include <iostream>

using namespace std;

class Stack
{
public:
  int *array;
  int currSize;
  int size;
  int topIndex;
  int addCount;

  int top()
  {
    if(topIndex == 0)
      return -1;

    return array[topIndex-1];
  }

  bool isEmpty()
  {
    if(size > 0)
      return false;
    
    return true;
  }

  void push(int x)
  {
    if(topIndex == currSize)
    {
      int *newArray;
      newArray = new int[currSize + addCount];

      for(int i = 0; i < topIndex; i++)
        newArray[i] = array[i];

      delete[] array;
      array = newArray;
      
      cout << "Increasing size by " << addCount << ". New Size: " << currSize + addCount << "\n";
      currSize = currSize + addCount;
    }
  
    array[topIndex] = x;
    topIndex++;
    
  }
  
  void pop()
  {
    topIndex--;
  }

  void print()
  {
    for(int i= topIndex-1; i>=0; i--)   
      cout << array[i] << "\t";

    cout << "\n";
    cout << "Top Index: " << topIndex-1  << "\n";
    cout << "Top Elem: " << array[topIndex-1] << "\n";
  }


  Stack() : currSize(3), addCount(2), topIndex(0)
  { 
    array = new int[currSize];
  }

  ~Stack(){}

  
};


void runDynamicStack()
{
  Stack S;

  S.push(5);
  S.push(3);

  S.print();

  S.push(44);

  S.print();

  S.push(22);
  S.print();
  S.push(11);
  S.print();
  S.push(13);
  S.print();
  S.push(78);
  S.print();

  S.pop();

  S.print();

  S.pop();

  S.print();

  S.pop();
}