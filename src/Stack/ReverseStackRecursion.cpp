//Rathinavel Sankaralingam
//Mar 08, 2020


#include <iostream>
#include <stack>

using namespace std;

void recurseHelper(stack<int> &stk);

void runReverseStackRecursion()
{
  stack<int> stk;
  
  for(int i=1; i<=6; i++)
    stk.push(i);

  
  recurseHelper(stk);

  while(!stk.empty())
  {
    cout << stk.top() << "\t"; stk.pop();
  }
}

void recurseHelper(stack<int> &stk)
{
  if(stk.empty())
    return;

  int top = stk.top(); stk.pop();

  recurseHelper(stk);

  stk.push(top);

  
}