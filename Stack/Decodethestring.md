<p>[Approach 1] Time Complexity: O(N + M) Space Complexity: O(N + M)
<br>When you see a [, you push the string you've built so far onto a stack and start a new, empty string for the inner part.

<br>When you see a ], you finish the inner part, pop your old work, and attach the repeated inner part to it.

<br>This avoids the inefficient process of decoding a string and then pushing it back onto a character stack.</p>

```cpp
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int currentNum = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                currentNum = currentNum * 10 + (ch - '0');
            } else if (ch == '[') {
                // Save the current state
                countStack.push(currentNum);
                stringStack.push(currentString);
                
                // Reset for the new nested segment
                currentNum = 0;
                currentString = "";
            } else if (ch == ']') {
                // Retrieve the saved state
                int k = countStack.top();
                countStack.pop();
                
                string prevString = stringStack.top();
                stringStack.pop();
                
                // Build the decoded segment
                string temp = "";
                for (int i = 0; i < k; ++i) {
                    temp += currentString;
                }
                
                // Restore the previous string and append the new segment
                currentString = prevString + temp;
            } else {
                // It's a letter, just append
                currentString += ch;
            }
        }
        return currentString;
