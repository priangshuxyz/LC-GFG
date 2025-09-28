<p>[Approach 1] Using an Auxiliary Stack - O(1) Time and O(n) Space
<p>Use two stacks: one to store actual stack elements and the other as an auxiliary stack to store minimum values. The idea is to do push() and pop() operations in such a way that the top of the auxiliary stack is always the minimum.</p></p>

```cpp

class SpecialStack {
private:
    stack<int> st;
    stack<int> minStk;
public:
    void push(int x) {
        st.push(x);
        // If the minStack is empty or the new element is smaller than 
        // the top of minStack, push it onto minStack
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        } else {
            // Otherwise, push the top element of minStack 
            // again to keep the minimum unchanged
            minStack.push(minStack.top());
        }
    }
    // Pop the top element from the stack
    void pop() {
        if (st.empty()) {
            return;
        }
        // Pop from both stacks
        st.pop();
        minStack.pop();
    }
    // Return the top element of the stack without removing it
    int peek() {
        if (st.empty()) {
            return -1;
        }
        return st.top();
    }
    bool isEmpty() {
        // Check if stack is empty
        return st.empty();
    }
    // Get the minimum element in the stack
    int getMin() {
        if (minStack.empty()) {
            return -1;
        }
        return minStack.top();
    }
};
```

<p>[Approach 3] Without Extra Space- O(1) Time and O(1) Space
<br>The idea is to use a variable minEle to track the minimum element in the stack. Instead of storing the actual value of minEle in the stack, we store a modified value when pushing an element smaller than minEle.</p>
