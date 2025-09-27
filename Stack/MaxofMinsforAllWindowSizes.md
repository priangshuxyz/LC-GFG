<p>[Naive Approach] By Checking All Subarrays O(n3) Time and O(1) Space
<p>The idea is to compute the minimum of every possible window, For each window size from 1 to n and find the maximum of those minimums.</p></p>

```cpp
    int n = arr.size();
    vector<int> res(n);
    // for each window size k
    for (int k = 1; k <= n; k++) {
        int maxMin = INT_MIN;
        // slide window of size k
        for (int i = 0; i <= n - k; i++) {
            int minval = INT_MAX;
            // find minimum in current window
            for (int j = i; j < i + k; j++) {
                minval = min(minval, arr[j]);
            }
            maxMin = max(maxMin, minval);
        }
        res[k - 1] = maxMin;
    }
    return res;
```

<p>[Better Approach] Sliding Window Minimum using Deque - O(n2) Time and O(n) Space
<p>The idea is to use the sliding window minimum technique (with a deque) to efficiently find the minimum element of every subarray of size k. By doing this for each window size k = 1 … n, we can compute the maximum of these minimums.</p></p>

```cpp
    int n = arr.size();
    vector<int> res(n);
    // iterate over all window sizes
    for (int k = 1; k <= n; k++) {
        deque<int> dq;
        int maxMin = INT_MIN;
        // process first k elements
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && arr[i] <= arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        // slide the window
        for (int i = k; i < n; i++) {
            maxMin = max(maxMin, arr[dq.front()]);
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            while (!dq.empty() && arr[i] <= arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        maxMin = max(maxMin, arr[dq.front()]);
        res[k - 1] = maxMin;
    }
    return res;
```
<p>[Expected Approach] Using Stack - O(n) Time and O(n) Space
<li>Find Boundaries: For each element, use a monotonic stack to find its nearest smaller neighbors (left and right). This defines the maximum window length where it's the minimum.</li>
<li>Map Candidates: Create an answer array ans. For each element arr[i], use its calculated window length to update ans[length] = max(ans[length], arr[i]).</li>
<li>Finalize: Iterate backwards through ans, setting ans[i] = max(ans[i], ans[i+1]) to propagate the final answers to all smaller window sizes.</li>
</p>

```cpp
    int n = arr.size();
    vector<int> res(n), len(n + 1, 0);
    stack<int> st;
    // find window sizes for each element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            int top = st.top();
            st.pop();
            int left = st.empty() ? -1 : st.top();
            int right = i;
            int windowSize = right - left - 1;
            len[windowSize] = max(len[windowSize], arr[top]);
        }
        st.push(i);
    }
    // process remaining elements in stack
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        int left = st.empty() ? -1 : st.top();
        int right = n;
        int windowSize = right - left - 1;
        len[windowSize] = max(len[windowSize], arr[top]);
    }
    for (int i = 1; i <= n; i++) {
        res[i - 1] = len[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        res[i] = max(res[i], res[i + 1]);
    }
    return res;
```

<p>LC Solution</p>
```cpp
    vector<int> result;
    deque<int> dq; // Stores indices of elements

    for (int i = 0; i < nums.size(); ++i) {
        // 1. Remove elements from the front that are out of the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // 2. Remove elements from the back that are smaller than the current element
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Add the current element's index to the back
        dq.push_back(i);

        // Once the window is full, add the max (at the front) to the result
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
