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
```

<p>[Expected Approach] Checking Last Merged Interval – O(n*log(n)) Time and O(n) Space

In the previous approach, for each range we are checking for possible overlaps by iterating over all the remaining ranges till the end. We can optimize this by checking only those intervals that overlap with the last merged interval. Since the intervals will be sorted based on starting point, so if we encounter an interval whose starting time lies outside the last merged interval, then all further intervals will also lie outside it. </p>

```cpp
vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
    // Sort intervals based on start values
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    res.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        vector<int>& last = res.back();
        vector<int>& curr = arr[i];
        // If current interval overlaps with the last merged
        // interval, merge them 
        if (curr[0] <= last[1]) 
            last[1] = max(last[1], curr[1]);
        else 
            res.push_back(curr);
    }
    return res;
}
