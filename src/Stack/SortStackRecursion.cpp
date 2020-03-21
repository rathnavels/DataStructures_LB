//Rathinavel Sankaralingam
//Mar 20, 2020


#include <iostream>
#include <stack>

using namespace std;
void helper(stack<int> &stk);

void runSortStackRecursion()
{

  std::stack<int> stk;

  stk.push(5);
  stk.push(8);
  stk.push(3);
  stk.push(7);
  stk.push(2);

  helper(stk);

  while(!stk.empty())
  {
    cout << stk.top() << "\t"; stk.pop();
  }

}

void helper(stack<int> &stk)
{

  if(stk.empty())
    return;

  int top = stk.top();
  stk.pop();

  helper(stk);

  if(stk.empty())
  {
    stk.push(top);
    return;
  }
  
  if(!stk.empty())
  {
    if(top > stk.top())
    {
      int temp = stk.top();
      stk.pop();
      stk.push(top);
      stk.push(temp);
    }
    else
      stk.push(top);
  }
  
}