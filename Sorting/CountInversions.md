<p>[Naive Approach] Using Two Nested Loops - O(n^2) Time and O(1) Space

The main idea of this approach is to count the total number of inversions in an array using a simple, brute-force technique. This technique relies on nested loops to check every possible pair of elements in the array. The process begins with the outer loop iterating from the first element up to the second-to-last element (index i). For each element at index i, the inner loop then iterates through all subsequent elements in the array (index j=i+1 to the end). This structure ensures that all pairs (i,j) where i<j are examined. Inside the inner loop, a comparison is made: if arr[i]>arr[j], it signifies an inversion, and a running count (invCount) is incremented > arr[j], if so, it means there is an inversion, and the invCount is incremented.].
</p>

```cpp
    int n = arr.size(); 
    int invCount = 0; 
    // Loop through the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // If the current element is greater 
            // than the next, increment the count
            if (arr[i] > arr[j])
                invCount++;
        }
    }
    return invCount;
