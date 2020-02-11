//Rathinavel Sankaralingam
//Feb 11, 2020

// LeetCode 232
// Implement Queue using Stack Data Structure

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    std::stack<int> stkQueue; 
    MyQueue() 
    {
      
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        stkQueue.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        int retValue;
        std::stack<int> localStack;
        
        while(!stkQueue.empty())
        {
            localStack.push(stkQueue.top());
            stkQueue.pop();
        }
        
        retValue = localStack.top();
        localStack.pop();
        
        while(!localStack.empty())
        {
            stkQueue.push(localStack.top());
            localStack.pop();
        }
        
        return retValue;
    }
    
    /** Get the front element. */
    int peek() 
    {
        int retValue;
        std::stack<int> localStack;
        
        while(!stkQueue.empty())
        {
            localStack.push(stkQueue.top());
            stkQueue.pop();
        }
        
        retValue = localStack.top();
        
        while(!localStack.empty())
        {
            stkQueue.push(localStack.top());
            localStack.pop();
        }
        
        return retValue;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return stkQueue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */