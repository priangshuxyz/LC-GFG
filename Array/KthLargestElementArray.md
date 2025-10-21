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
```

<p>[Expected Approach] Using Priority Queue(Min-Heap) - O(n * log(K)) time and O(K) space

The idea is to maintain a min-heap (priority queue) of size K while iterating through the array. This approach ensures that the heap always contains the K largest elements encountered so far. As we add elements to the heap:

If the size of the heap exceeds K, we remove the smallest element. This ensures that the heap maintains only the K largest elements.
By the end of the process, the top element of the min-heap (which is the smallest of the K largest elements) will be the k-th largest element in the array.</p>

```java
    public static int kthLargest(int[] arr, int K) {
        // Min heap to store K largest elements
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        // Iterate through the array elements
        for (int val : arr) {
            // Add current element to the min heap
            pq.add(val);
            // If heap exceeds size K, remove smallest element
            if (pq.size() > K)
                pq.poll();
        }
        // Top of the heap is the K'th largest element
        return pq.peek();
    }
