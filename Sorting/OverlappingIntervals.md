<p>[Naive Approach] Checking All Possible Overlaps – O(n^2) Time and O(n) Space

A simple approach is to group all the intervals by sorting them then start from the first interval and compare it with all other intervals for overlaps. If the first interval overlaps with any other interval, then remove the other interval from the list and merge the other into the first interval. Repeat the same steps for the remaining intervals after the first.</p>

```cpp
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    // Checking for all possible overlaps
    for (int i = 0; i < n; i++) {
        int start = arr[i][0];
        int end = arr[i][1];
        // Skipping already merged intervals
        if (!res.empty() && res.back()[1] >= end)
            continue;
        // Find the end of the merged range
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end)
                end = max(end, arr[j][1]);
        }
        res.push_back({start, end});
    }
    return res;
