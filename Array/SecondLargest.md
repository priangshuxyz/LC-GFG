<p>[Naive Approach] Using Sorting

Time Complexity: O(n*log(n)), as sorting the array takes O(n*log(n)) time and traversing the array can take O(n) time in the worst case.
Auxiliary space: O(1), as no extra space is required.

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
```
<p>[Better Approach] Two Pass Search
Time Complexity: O(2*n) = O(n), as we are traversing the array two times.
Auxiliary space: O(1)

The approach is to traverse the array twice. In the first traversal, find the maximum element. In the second traversal, find the maximum element ignoring the one we found in the first traversal.</p>

```cpp
    int n = arr.size();
    int largest = -1, secondLargest = -1;
    // finding the largest element
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest)
            largest = arr[i];
    }
    // finding the second largest element
    for (int i = 0; i < n; i++) {
        // Update second largest if the current element is greater
        // than second largest and not equal to the largest
        if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
```
<p>[Expected Approach] One Pass Search
Time Complexity: O(n), as we are traversing the array only once.
Auxiliary space: O(1)

The idea is to keep track of the largest and second largest element while traversing the array. Initialize largest and secondLargest with -1. Now, for any index i,

If arr[i] > largest, update secondLargest with largest and largest with arr[i].

Else If arr[i] < largest and arr[i] > secondLargest, update secondLargest with arr[i]. </p>

```cpp
    int n = arr.size();
    int largest = -1, secondLargest = -1;
    // finding the second largest element
    for (int i = 0; i < n; i++) {
        // If arr[i] > largest, update second largest with
        // largest and largest with arr[i]
        if(arr[i] > largest) {
        	secondLargest = largest;
            largest = arr[i];
        }
        // If arr[i] < largest and arr[i] > second largest, 
        // update second largest with arr[i]
      	else if(arr[i] < largest && arr[i] > secondLargest) {
        	secondLargest = arr[i];
        }
    }
    return secondLargest;
