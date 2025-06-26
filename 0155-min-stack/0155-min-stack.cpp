#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> s;         // Main stack to store all values
    stack<int> minStack;  // Auxiliary stack to keep track of minimums

public:
    // Constructor: Initializes the object
    MinStack() {
        // No initialization logic needed for empty stacks
    }

    // Pushes the element 'val' onto the stack
    void push(int val) {
        s.push(val); // Push the value into the main stack
        // If minStack is empty or val is <= current min, push it to minStack too
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    // Removes the element on the top of the stack
    void pop() {
        // If the top element is also the minimum, pop it from minStack
        if (!s.empty() && s.top() == minStack.top()) {
            minStack.pop();
        }
        s.pop(); // Pop from the main stack
    }

    // Returns the top element of the stack
    int top() {
        return s.top(); // Top of the main stack
    }

    // Retrieves the minimum element in the stack
    int getMin() {
        return minStack.top(); // Top of minStack is the current minimum
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);              // Push value to the stack
 * obj->pop();                  // Remove top value from stack
 * int topVal = obj->top();     // Get top value of stack
 * int minVal = obj->getMin();  // Get minimum value in stack
 */
