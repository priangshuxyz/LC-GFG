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

<p>[Expected Approach] Using Merge Step of Merge Sort - O(n*log n) Time and O(n) Space

The main idea is to count inversions using a modified Merge Sort algorithm.

This approach works recursively by:

Divide and Recurse ➗: Dividing the array into left and right halves and recursively calculating the inversions within each half.

Count Cross Inversions ✖️: While merging the two sorted halves, counting the "cross inversions," which are pairs where an element from the left half is greater than an element from the right half.

Sum Total ➕: Summing the inversions from the left half, the right half, and the cross inversions to get the final total.

This method efficiently counts all inversions while simultaneously sorting the array.</p>

```cpp
int countAndMerge(vector<int>& arr, int l, int m, int r) {
    // Counts in two subarrays
    int n1 = m - l + 1, n2 = r - m;
    // Set up two vectors for left and right halves
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
    // Initialize inversion count (or result) and merge two halves
    int res = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        // No increment in inversion count if left[] has a 
        // smaller or equal element
        if (left[i] <= right[j]) 
            arr[k++] = left[i++];
        // If right is smaller, then it is smaller than n1-i 
      	// elements because left[] is sorted
        else {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }
    // Merge remaining elements
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
}
// Function to count inversions in the array
int countInv(vector<int>& arr, int l, int r){
    int res = 0;
    if (l < r) {
        int m = (r + l) / 2;
        // Recursively count inversions in the left and 
        // right halves
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);

        // Count inversions such that greater element is in 
      	// the left half and smaller in the right half
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}
int inversionCount(vector<int> &arr) {
  	int n = arr.size();
  	return countInv(arr, 0, n-1);
}
