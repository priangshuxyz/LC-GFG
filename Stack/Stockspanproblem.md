<p>[Naive Approach] Using Nested Loop - O(n2) Time and O(1) Space
The idea is to check, for each day, how many consecutive previous days had stock prices less than or equal to the current day’s price. This can be done by moving leftwards from the current index until a higher price is found or the beginning of the array is reached.</p>

```cpp
    int n = arr.size(); 
    vector<int> span(n, 1);
    
    // Calculate span for each day
    for (int i = 1; i < n; i++) {
        
        // Traverse left while the next element
        // on the left is smaller than arr[i]
        for (int j = i - 1; (j >= 0)
                      && (arr[i] >= arr[j]); j--) {
            span[i]++;
        }
    }

    return span;
```
<p>[Expected Approach] Using Stack - O(n) Time and O(n) Space
The idea is to use a stack to directly find this first previous greater element for every day, instead of checking all consecutive smaller ones. Once we know that index, we can compute the span as:
Span[i] = currentIndex − indexOfPreviousGreaterElement</p>

```cpp
    int n = arr.size(); 
    vector<int> span(n);  
    stack<int> st;  
    // Process each day's price
    for (int i = 0; i < n; i++) {
        // Remove elements from the stack while the current
        // price is greater than or equal to stack's top price
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        // If stack is empty, all elements to the left are smaller
        // Else, top of the stack is the last greater element's index
        if (st.empty()) {
            span[i] = (i + 1);
        }
        else {
            span[i] = (i - st.top());
        }
        // Push the current index to the stack
        st.push(i);
    }
    return span;
