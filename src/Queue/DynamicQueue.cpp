//Rathinavel Sankaralingam
//Mar 21, 2020


#include <iostream>
using namespace std;

class Queue
{
public:
  int *array;
  int currSize;
  int size;
  int backIndex;
  int addCount;

  int front()
  {
    if(backIndex == 0)
      return -1;

    return array[0];
  }

  bool isEmpty()
  {
    if(size > 0)
      return false;
    
    return true;
  }

  void push(int x)
  {
    if(backIndex == currSize)
    {
      int *newArray;
      newArray = new int[currSize + addCount];

      for(int i = 0; i < backIndex; i++)
        newArray[i] = array[i];

      delete[] array;
      array = newArray;
      
      cout << "Increasing size by " << addCount << ". New Size: " << currSize + addCount << "\n";
      currSize = currSize + addCount;
    }
  
    array[backIndex] = x;
    backIndex++;
    
  }
  
  void pop()
  {
    for(int i=1; i<=backIndex; i++)
      array[i-1] = array[i];

    backIndex--;
  }

  void print()
  {
    for(int i= 0; i<backIndex; i++)   
      cout << array[i] << "\t";

    cout << "\n";
    cout << "Front Elem: " << array[0] << "\n";
  }


  Queue() : currSize(3), addCount(2), backIndex(0)
  { 
    array = new int[currSize];
  }

  ~Queue(){}

  
};

void runDynamicQueue()
{
  Queue Q;

  Q.push(5);
  Q.push(3);
  Q.push(44);
  Q.print();
  Q.push(55);
  Q.push(65);
  Q.push(75);
  Q.print();
  Q.pop();
  Q.print();
  Q.pop();
  Q.print();
  Q.push(32);
  Q.print();
  Q.push(54);
  Q.print();
}