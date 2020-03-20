//Rathinavel Sankaralingam
//Mar 08, 2020


#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void recurseHelper(stack<int> &stk, queue<int> &que);

void runReverseStackRecursion()
{
  stack<int> stk;

  queue<int> que;
  
  for(int i=1; i<=6; i++)
  {
    stk.push(i);
  }

  recurseHelper(stk,que);

  while(!stk.empty())
  {
    cout << stk.top() << "\t"; stk.pop();
  }
}

void recurseHelper(stack<int> &stk, queue<int> &que)
{
  if(stk.empty())
    return;

  int top = stk.top(); stk.pop();
  que.push(top);

  recurseHelper(stk,que);

  stk.push(que.front());
  que.pop();

  
}