//Rathinavel Sankaralingam
//Jan 25, 2020


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void runValidateStackSequences() 
{
    vector<int> pushed = {2,1,0};
    vector<int> popped = {1,2,0};
    bool IsValid = true; 
    int popIdx = 0;
    std::stack<int> stk;
    for(int i=0; i<pushed.size(); i++)
    {
        while(!stk.empty() && stk.top()==popped[popIdx])
        {
            stk.pop();
            popIdx++;
        }
        stk.push(pushed[i]);
    }
    while(stk.empty()==false)
    {
        if(stk.top()==popped[popIdx])
        {
            stk.pop();
            popIdx++;
        }
        else
        {
            IsValid = false;
            break;
        }
    }
        
    if(IsValid)
      std::cout << "True";
    else
      std::cout << "False";
}