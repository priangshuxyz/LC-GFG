<p>[Naive Approach] - Using Nested Loops - O(n * k) Time and O(1) Space
<br>The idea is to run the nested loops, the outer loop will mark the starting point of the subarray of length k, and the inner loop will run from the starting index to index + k, and print the maximum element among these k elements. </p>

```cpp

    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    int n = arr.size();
    // to store the results
    vector<int> res;
    for (int i = 0; i <= n - k; i++) {
        // Find maximum of subarray beginning
        // with arr[i]
        int max = arr[i];
        for (int j = 1; j < k; j++) {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        res.push_back(max);
    }
    return res;
