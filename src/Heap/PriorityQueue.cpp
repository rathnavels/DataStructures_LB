//Rathinavel Sankaralingam
//Apr 25, 2020


#include <iostream>
#include <queue>

using namespace std;

void showPQ(priority_queue<int, vector<int>, greater<int>>  pq)
{
  while (!pq.empty())
  {
    cout << pq.top() << "\t";
    pq.pop();
  }
}

void runPriorityQueue()
{
  priority_queue<int, vector<int>, greater<int>> pq;

  int K = 4;

  pq.push(10);
  pq.push(40);
  pq.push(35);
  pq.push(28);
  pq.push(12);
  pq.emplace(15);

  showPQ(pq);

  cout << "\n" << pq.size() ;
  cout << "\n" << pq.top();
}