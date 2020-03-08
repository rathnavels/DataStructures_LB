//Rathinavel Sankaralingam
//Mar 08, 2020


#include <iostream>
#include <queue>

using namespace std;

void recurseHelper(queue<int> &que);

void runReverseQueueRecursion()
{

  queue<int> que;
  for(int i=0; i<=6; i++)
    que.push(i);

  recurseHelper(que);

  while(!que.empty())
  {
    std::cout << que.front() << "\t";
    que.pop();
  }
  
}

void recurseHelper(queue<int> &que)
{
  if(que.empty())
    return;

  int x = que.front(); que.pop();

  recurseHelper(que);

  que.push(x);
}
