//Rathinavel Sankaralingam
//Feb 26, 2020

// Evaluate Post Fix Expression
// a.k.a Reverse Polish Notation

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

void runPostFix()
{
  string str ="3 40 + 2 x 1 +" ;
  stack<int> stk;
  stringstream ss(str);
  char delimiter = ' ';
  string token;

  while(getline(ss,token,delimiter))
  {
    if(token == "/" || token == "x" || token == "+" || token == "-")
    {
      int i = stk.top(); stk.pop();
      int j = stk.top(); stk.pop();
      char c = token[0];
      switch (c)
      {
        case '/':
          stk.push(i/j);
        break;
        case 'x':
          stk.push(i*j);
        break;
        case '+':
          stk.push(i+j);
        break;
        default:
          stk.push(i-j);
        break;
      }
    }
    else
    {
      stk.push(stoi(token));
    }
  }

  std::cout <<  stk.top();
}