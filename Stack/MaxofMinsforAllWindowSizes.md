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
