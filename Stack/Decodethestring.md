<p>[Approach 1] Using Two Stacks - O(n) Time and O(n) Space
<br>Use two stacks (one for numbers, one for characters). When ']' is found, pop till '[' to form a substring, repeat it using the top number, and push back — final stack gives the decoded string.</p>

```cpp
    stack<int> numStack;
    stack<char> charStack;
    string temp = "";
    string res = "";
    for (int i = 0; i < s.length(); i++) {
        int cnt = 0;
        // If Digit, convert it into number and 
      	// push it into integerstack.
        if (s[i] >= '0' && s[i] <= '9') {
            while (s[i] >= '0' && s[i] <= '9') {
                cnt = cnt * 10 + s[i] - '0';
                i++;
            }
            i--;
            numStack.push(cnt);
        }
        // If closing bracket ']' is encountered
        else if (s[i] == ']') {
            temp = "";
            cnt = numStack.top();
            numStack.pop();
          	// pop element till opening bracket '[' is not found in the
        	// character stack.
            while (charStack.top() != '[') {
                temp = charStack.top() + temp;
                charStack.pop();
            }
            charStack.pop();
            // Repeating the popped string 'temp' count number of times.
            for (int j = 0; j < cnt; j++)
                res = res.append(temp);
            // Push it in the character stack.
            for (int j = 0; j < res.length(); j++)
                charStack.push(res[j]);
            res = "";
        }
        else
            charStack.push(s[i]);
    }
    // Pop all the element, make a string and return.
    while (!charStack.empty()) {
        res = charStack.top() + res;
        charStack.pop();
    }

    return res;
