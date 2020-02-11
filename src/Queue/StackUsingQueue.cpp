//Rathinavel Sankaralingam
//Feb 11, 2020


#include <iostream>
#include <queue>

// Stack Using Queue Data Structure
// Leetcode 225


class MyStack {
public:
    /** Initialize your data structure here. */
    std::queue<int> qStack;
    MyStack() 
    {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        qStack.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        int retValue;
        std::queue<int> tempQue;
        
        while(!qStack.empty())
        {
            tempQue.push(qStack.front());
            qStack.pop();
        }
        
        retValue = tempQue.back();
        
        while(!tempQue.empty())
        {
            if(tempQue.size()!=1)
                qStack.push(tempQue.front());
            
            tempQue.pop();
        }
        
        
        return retValue;
    }
    
    /** Get the top element. */
    int top() 
    {
        return qStack.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        return qStack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */