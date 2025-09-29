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
<br>The idea is to use priority queue or heap data structure to make sure that heap has largest item of the current window.
<li>Create a max heap of the first k items </li>
<li>Now iterate one by one. While the next item to be added is greater than the heap top, remove the top. We mainly make sure that the greater items of the previous window are not there in a heap.</li></p>

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
