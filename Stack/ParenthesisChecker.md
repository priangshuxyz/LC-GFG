<p>Using Stack - O(n) Time and O(n) Space
We use a stack to ensure that every opening has a matching closing. Each opening is pushed onto the stack. When a closing appears, we check if the stack has a corresponding opening to pop; if not, the string is unbalanced. After processing the entire string, the stack must be empty for it to be considered balanced.</p>
```cpp
    
    stack<char> st; 
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            // No opening bracket
            if (st.empty()) return false; 
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
            // Pop matching opening bracket
            st.pop(); 
        }
    }
    // Balanced if stack is empty
    return st.empty();
