//Rathinavel Sankaralingam
//Mar 08, 2020


#include <iostream>
#include <string>
#include <stack>
using namespace std;


//Input :  a+b*(c^d-e)^(f+g*h)-i
//Output:  abcd^e-fgh*+^*+i

int getPriority(char c)
{
  int priority;
  switch (c)
  {
    case '+':
    case '-':
      priority = 1;
    break;

    case '*':
    case '/':
     priority = 2;
    break;

    case '^':
      priority = 3;
    break;

    default:
      priority = -1;
    break;
  }
  return priority;
}

void runInfixToPostfix()
{
  std::string str = "(A+B)+(C+D)";
  stack<char> stk;


  string retStr = "";

  
  for(int i=0; i<str.size(); i++)
  {
    char c = str[i];
    if(c == '(')
    {
      stk.push(c);
    }
    else if(c == ')')
    {
      while(!stk.empty() && stk.top()!='(')
      {
        char temp = stk.top(); stk.pop();
        retStr += temp;
      }
      stk.pop();
    }
    else if(c =='+' || c == '-' || c == '*' || c == '/'  || c =='^')
    {
      if(stk.empty())
        stk.push(c);
      else
      {
        while(!stk.empty() && (getPriority(c) <= getPriority(stk.top())))
        {
          char temp = stk.top(); stk.pop();
          retStr += temp;
        } 
        stk.push(c);
      }
    }
    else
    {
      retStr += c;
    }

  }
  std::cout << retStr;
}