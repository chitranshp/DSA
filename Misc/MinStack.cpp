// https://leetcode.com/problems/min-stack/description/
/*
Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Methods pop, top and getMin operations will always be called on non-empty stacks.

*/

class MinStack {
  
stack<int> s1;          //To track minimum element
stack<int> s2;          //For rest of stack properties
  
public:
    MinStack() {
        
    }
    
    void push(int val) 
    {
        if(s1.empty() || val <= getMin())  
            s1.push(val);
        s2.push(val);
    }
    
    void pop() 
    {
        if(!s1.empty() && s2.top() == getMin()) 
            s1.pop();

        s2.pop(); 
    }
    
    int top() 
    {
        return s2.top();  
    }
    
    int getMin() 
    {
        return s1.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
