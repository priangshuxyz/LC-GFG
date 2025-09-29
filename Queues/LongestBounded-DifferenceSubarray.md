<p>[Naive Approach] Checking all subarrays - O(n3) Time and O(1) Space
<br>The idea is to consider all subarrays one by one, find the maximum and minimum element of that sub-array and check if their difference is not greater than x. Among all such sub-arrays print the longest sub-array.</p>

```cpp
    int n = arr.size();
    int start = 0, maxLen = 1;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            // Find minimum and maximum elements
            int mini = INT_MAX, maxi = INT_MIN;
            for (int k=i; k<=j; k++) {
                mini = min(mini, arr[k]);
                maxi = max(maxi, arr[k]);
            }
            // If difference is less than x,
            // compare length of subarray 
            if (maxi - mini <= x && maxLen < j-i+1) {
                maxLen = j-i+1;
                start = i;
            }
        }
    }
    vector<int> res;
    for (int i = start; i < start+maxLen; i++) {
        res.push_back(arr[i]);
    }
    return res;
```

<p>[Better Approach] Using Sliding Window and Sorted Map - O(n * log n) Time and O(n) Space
<br>We use a sliding window with an ordered map to maintain the minimum and maximum values in the current subarray. The window expands until the absolute difference exceeds x; if it does, we shrink the window from the left until the condition is satisfied again.</p>

```cpp
    int n = arr.size();
    int maxLen = 0;
    int beginning = 0;
    map<int, int> window;
    // Initialize the window
    int start = 0, end = 0;
    for (; end < n; end++) {
        // Increment the count of that element in the window
        window[arr[end]]++;
        // maximum and minimum element in current window
        auto minimum = window.begin()->first;
        auto maximum = window.rbegin()->first;
        // If the difference is not greater than X
        if (maximum - minimum <= x) {
            // Update the length of the longest subarray and
            // store the beginning of the sub-array
            if (maxLen < end - start + 1) {
                maxLen = end - start + 1;
                beginning = start;
            }
        }
        // Decrease the size of the window
        else {
            while (start < end) {
                // Remove the element at start
                window[arr[start]]--;
                // Remove the element from the window
                // if its count is zero
                if (window[arr[start]] == 0) {
                    window.erase(window.find(arr[start]));
                }
                // Increment the start of the window
                start++;
                // maximum and minimum element in the
                // current window
                auto minimum = window.begin()->first;
                auto maximum = window.rbegin()->first;
                // Stop decreasing the size of window
                // when difference is not greater
                if (maximum - minimum <= x)
                    break;
            }
        }
    }
    // Return the longest sub-array
    vector<int> res;
    for (int i = beginning; i < beginning + maxLen; i++)
        res.push_back(arr[i]);
    return res;
