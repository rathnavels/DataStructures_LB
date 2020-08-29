//Rathinavel Sankaralingam
//May 13, 2020

// Leetcode


// Decode string 
// 2[a3[c]] --> acccaccc
// 3[b]3[ca] --> bbbcacaca

#include <iostream>
#include <string>
#include <stack>
#include <set>

using namespace std;

enum
{
  NUM = 0,
  STR
};

void runDecodeString()
{
  string str = "2[t2[u1[vw2[x3[yz]]]]]";
  stack<pair<string,int>> stk;
  string ans;
  

  for (int i = 0; i < str.length(); i++)
  {
    if (isdigit(str[i]))
    {
      string numString = "";
      while (isdigit(str[i]))
      {
        numString += str[i];
        i++;
      }

      i--;

      stk.push(make_pair(numString,NUM));
    }
    else if (str[i] == '[')
    {
      continue;
    }
    else if (isalpha(str[i]))
    {
      string charString = "";
      while (isalpha(str[i]))
      {
        charString += str[i];
        i++;
      }
      i--;

      if (get<1>(stk.top()) == STR)
      {
        charString = get<0>(stk.top()) + charString;
        stk.pop();
      }
      stk.push(make_pair(charString,STR));
    }
    else
    {
      auto top1 = stk.top(); stk.pop();
      auto top2 = stk.top(); stk.pop();

      string toBePushed = "";
      int num = stoi(get<0>(top2));

      while (num--)
        toBePushed += get<0>(top1);
      
      if (stk.empty())
      {
        ans += toBePushed;
      }
      else
      {
        toBePushed = get<0>(stk.top()) + toBePushed;
        stk.pop();
        stk.push(make_pair(toBePushed,STR));
      }
    }
  }
  if (!stk.empty())
  {
    ans += get<0>(stk.top());
  }

  set<string> st;

  st.insert(ans);
  st.insert("tuvwxyzyzyzxyzyzyzuvwxyzyzyzxyzyzyztuvwxyzyzyzxyzyzyzuvwxyzyzyzxyzyzyz");
  
  for(string str : st)
    cout << str << endl;
}