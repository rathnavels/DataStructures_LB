//Rathinavel Sankaralingam
//Jan 18, 2020


// Input : 11, 13, 21, 3 42, 5
// output :
// 11 -- 13
// 13 -- 21
// 21 -- 42
// 3 -- 42
// 42 -- -1
// 5 -- -1

#include <iostream>
#include <vector>
#include <stack>

void runNGEStack()
{
  std::vector<int> elements = {4, 5, 2, 25, 7, 32, 8, 6};
  
  std::stack<int> stk;

  stk.push(elements[0]);

  for(int i=1; i<elements.size(); i++)
  {
    if(stk.empty())
    {
      stk.push(elements[i]);
      continue;
    }
    while(!stk.empty() &&  stk.top() < elements[i])
    {
      std::cout << stk.top() << "\t"  << elements[i] << "\n";
      stk.pop();
    }

    stk.push(elements[i]);
  }

  while(stk.empty() == false)
  {
    std::cout << stk.top() << "\t"  << "-1" << "\n";
    stk.pop();
  }
}