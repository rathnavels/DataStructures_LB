//Rathinavel Sankaralingam
//Mar 08, 2020


#include <iostream>
#include <stack>

using namespace std;

void deleteMid(stack<int> &stk, int N, int curr=0)
{

  if(stk.empty())
    return;

  int x = stk.top(); stk.pop();

  deleteMid(stk,N,curr+1);

  if(curr != N/2)
    stk.push(x);
}

void runDeleteMiddleElement()
{
  stack<int> stk;

  for(int i=1; i<=6; i++)
    stk.push(i);

  deleteMid(stk,stk.size());

  while(!stk.empty())
  {
    cout << stk.top();
    stk.pop();
  }
}