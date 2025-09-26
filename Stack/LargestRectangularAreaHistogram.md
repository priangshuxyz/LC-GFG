<p>[Naive Approach] By Finding Max Area of Rectangles all Heights - O(n2) Time and O(1) Space
The idea is to fix each bar as the height of the rectangle and expand towards the left and right while the bars are at least as tall as the current bar. For every valid step, we keep adding the current bar’s height to the area. By doing this for all bars and keeping track of the maximum value.</p>

```cpp
    int res = 0, n = arr.size();
    // Consider every bar one by one
    for(int i = 0; i < n; i++){
        int curr = arr[i];
        // Traverse left while we have a greater height bar
        for(int j = i-1; j>=0 && arr[j] >= arr[i]; j--)
             curr += arr[i];
        // Traverse right while we have a greater height bar      
        for(int j = i+1; j<n && arr[j] >= arr[i]; j++)
            curr += arr[i];
        res = max(res, curr);
    }
    
    return res;
