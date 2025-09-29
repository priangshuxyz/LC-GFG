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
