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
