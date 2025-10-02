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
```

<p>[Expected Approach] Using Merge Step of Merge Sort - O(n*log n) Time and O(n) Space </p>
<h2>Merge Sort Inversion Counting</h2>
    <p>The main idea is to **count inversions using a modified Merge Sort algorithm**.</p>

    <p>This approach works recursively by:</p>

    <ul>
        <li>
            **Divide and Recurse** ➗: Dividing the array into left and right halves and recursively calculating the inversions within each half.
        </li>
        <li>
            **Count Cross Inversions** ✖️: While **merging** the two sorted halves, counting the "cross inversions," which are pairs where an element from the left half is greater than an element from the right half.
        </li>
        <li>
            **Sum Total** ➕: Summing the inversions from the left half, the right half, and the cross inversions to get the final total.
        </li>
    </ul>
    <p>This method efficiently counts all inversions while simultaneously sorting the array.</p>
