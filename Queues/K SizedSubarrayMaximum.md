<p>[Naive Approach] - Using Nested Loops - O(n * k) Time and O(1) Space
<br>The idea is to run the nested loops, the outer loop will mark the starting point of the subarray of length k, and the inner loop will run from the starting index to index + k, and print the maximum element among these k elements. </p>

```cpp

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
```

<p>[Better Approach] - Using Max-Heap - (n * log n) Time and O(n) Space
<br>The idea is to use a priority queue (max heap) to find the largest item in the current window.
<br>The heap stores pairs of {value, index} to track both an element's value and its original position. First, the heap is initialized with the first k pairs. Then, for each subsequent element in the array, its {value, index} pair is added to the heap. Before recording the window's maximum, we check the top of the heap. While the index of the top element is outside the current window's bounds, we pop it. After removing any such stale elements, the value at the top of the heap is guaranteed to be the maximum for the current window.</p>

```cpp

    int n = arr.size();
    // to store the results
    vector<int> res;
    // to store the max value
    priority_queue<pair<int, int> > heap;
    // Initialize the heap with the first k elements
    for (int i = 0; i < k; i++)
        heap.push({ arr[i], i });
    // The maximum element in the first window
    res.push_back(heap.top().first);
    // Process the remaining elements
    for (int i = k; i < arr.size(); i++) {
        // Add the current element to the heap
        heap.push({ arr[i], i });
        // Remove elements that are outside the current
        // window
        while (heap.top().second <= i - k)
            heap.pop();
        // The maximum element in the current window
        res.push_back(heap.top().first);
    }
    return res;
```
<p>[Expected Approach] - Using Deque - O(n) Time and O(k) Space
<br>The algorithm maintains one crucial rule (an invariant) for the deque:
<br>The deque stores indices of elements from the current window, and it is always kept in decreasing order of their corresponding values in the nums array.
<br>Because of this rule, the index of the largest element in the current window is always at the front of the deque (dq.front()).</p>

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
