<p>[Naive Approach] Using Sorting
The idea is to sort the array in non-decreasing order. Now, we know that the largest element will be at index n - 1. So, starting from index (n - 2), traverse the remaining array in reverse order. As soon as we encounter an element which is not equal to the largest element, return it as the second largest element in the array. If all the elements are equal to the largest element, return -1.
</p>

```cpp
    int n = arr.size();
    // Sort the array in non-decreasing order
    sort(arr.begin(), arr.end());
    // start from second last element as last element is the largest
    for (int i = n - 2; i >= 0; i--) {
        // return the first element which is not equal to the 
        // largest element
        if (arr[i] != arr[n - 1]) {
            return arr[i];
        }
    }
    // If no second largest element was found, return -1
    return -1;
