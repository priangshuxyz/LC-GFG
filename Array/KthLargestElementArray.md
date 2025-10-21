<p>[Naive Approach] Using Sorting - O(n log(n)) time and O(1) space
  
The very basic approach is to sort the given array in descending order and return the element at the index K - 1 (zero-based indexing).</p>

```java
    static int kthLargest(Integer[] arr, int K) {
        int n = nums.length;
        // Sort the array in descending order
        Arrays.sort(nums);
        // Return K'th largest element
        return nums[n - k];
    }
