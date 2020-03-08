//Rathinavel Sankaralingam
//Jan 10, 2020


#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void runReverseQueueUsingStack()
{
  queue<int> Q;
  stack<int> S;

  Q.push(5);
  Q.push(4);
  Q.push(3);
  Q.push(2);
  Q.push(1);

    while(!Q.empty())
    {
      int q = Q.front();
      S.push(q);
      Q.pop();
    }

    while(!S.empty())
    {
      int s = S.top();
      Q.push(s);
      S.pop();
    }

    while(!Q.empty())
    {
      cout << Q.front();
      Q.pop();
    }
}