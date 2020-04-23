//Rathinavel Sankaralingam
//Apr 23, 2020

// Max Heap

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct PriorityQueue
{
private:
  vector<int> A;

  int parent(int i)
  {
    return (i-1)/2;
  }
  
  int leftChild(int i)
  {
    return (2*i)+1;
  }

  int rightChild(int i)
  {
    return (2*i)+2;
  }

  void heapifyDown(int i)
  {
    int left = leftChild(i);
    int right = rightChild(i);

    int largest = i;
    if(left < size() && A[left] > A[i])
      largest = left;

    if(right < size() && A[right] > A[largest])
      largest = right;

    if (largest != i)
    {
      swap(A[i],A[largest]);
      heapifyDown(largest);
    }
  }

  void heapifyUp(int i)
  {
    if (i && A[parent(i)] < A[i])
    {
      swap(A[i],A[parent(i)]);
      heapifyUp(parent(i));
    }
  }

public:
  unsigned int size()
  {
    A.size();
  }

  bool empty()
  {
    return (size == 0);
  }

  void push(int key)
  {
    A.push_back(key);

    int index = size()-1;
    heapifyUp(index);
  }

  void pop()
  {
    if(size() == 0)
    { 
      cout << "Heap is empty()";
    } 
    else
    {
      A[0] = A.back();

      A.pop_back();
      heapifyDown(0);
    }
  }

  int top()
  {

  }
};

void runMaxHeap()
{
  PriorityQueue pq;
}