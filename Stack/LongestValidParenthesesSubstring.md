<p>[Expected Approach - 1] Using Stack - O(n) Time and O(n) Space
<li>For every opening parenthesis, we push its index onto the stack.</li>
<li>For every closing parenthesis, we pop the stack.</li>
<li>If the stack becomes empty after popping, it means we've encountered an unmatched closing parenthesis, so we push the current index to serve as a base for the next potential valid substring.</li>
<li>If the stack is not empty, we calculate the length of the valid substring by subtracting the index at the top of the stack from the current index.</li>
<li>A variable maxLength keeps track of the maximum length of valid parentheses encountered during the traversal.</li>
</p>

```cpp
    stack<int> st;
    // Push -1 as the initial index to 
  	// handle the edge case
    st.push(-1);
    int maxLen = 0;
    for (int i = 0; i < s.length(); i++) {
        // If we encounter an opening parenthesis,
      	// push its index
        if (s[i] == '(') {
            st.push(i);
        } 
        else {
            // If we encounter a closing parenthesis,
          	// pop the stack
            st.pop();
            // If stack is empty, push the current index 
            // as a base for the next valid substring
            if (st.empty()) {
                st.push(i);
            } else {
                // Update maxLength with the current length 
                // of the valid parentheses substring
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    return maxLen;
