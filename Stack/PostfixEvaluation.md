<p>[Approach] Using Stack - O(n) Time and O(n) Space
<br>The idea is to use the property of postfix notation, where two operands are always followed by an operator. We iterate through the expression from left to right, and whenever we encounter an operand, we push it onto the stack. When we encounter an operator, we pop the top two elements from the stack, apply the operator on them, and then push the result back into the stack.</p>

```cpp

int floorDiv(int a, int b) {
    if (a * b < 0 && a % b != 0)
        return (a / b) - 1;
    return a / b;
}
int evaluatePostfix(vector<string>& arr) {
    stack<int> st;
    for (string token : arr) {
        // If it's an operand (number), push it onto the stack
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            st.push(stoi(token));
        } 
        // Otherwise, it must be an operator
        else {
            int val1 = st.top(); st.pop(); 
            int val2 = st.top(); st.pop(); 

            if (token == "+") st.push(val2 + val1);
            else if (token == "-") st.push(val2 - val1);
            else if (token == "*") st.push(val2 * val1);
            else if (token == "/") st.push(floorDiv(val2, val1));
            else if (token == "^") st.push((int)pow(val2, val1));
        }
    }
    return st.top();
}

