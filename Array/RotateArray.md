<p>[Naive Approach] Rotate one by one - O(n * d) Time and O(1) Space

In each iteration, shift the elements by one position to the left in a circular fashion (the first element becomes the last). Perform this operation d times to rotate the elements to the left by d positions.</p>

```java
  static void rotateArr(int[] arr, int d) {
        int n = arr.length;
        // Repeat the rotation d times
        for (int i = 0; i < d; i++) {
            // Left rotate the array by one position
            int first = arr[0];
            for (int j = 0; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[n - 1] = first;
        }
    }
```

<p>[Better Approach] Using Temporary Array - O(n) Time and O(n) Space

The idea is to use a temporary array of size n, where n is the length of the original array. If we left rotate the array by d positions, the last n - d elements will be at the front and the first d elements will be at the end.

Copy the last (n - d) elements of original array into the first n - d positions of temporary array.

Then copy the first d elements of the original array to the end of temporary array.

Finally, copy all the elements of temporary array back into the original array.</p>

```java
    static void rotateArr(int[] arr, int d) {
        int n = arr.length;
        // Handle case when d > n
        d %= n;
        // Storing rotated version of array
        int[] temp = new int[n];
        // Copy last n - d elements to the front of temp
        for (int i = 0; i < n - d; i++)
            temp[i] = arr[d + i];
        // Copy the first d elements to the back of temp
        for (int i = 0; i < d; i++)
            temp[n - d + i] = arr[i];
        // Copying the elements of temp in arr
        // to get the final rotated array
        for (int i = 0; i < n; i++)
            arr[i] = temp[i];
    }
```

<p>[Expected Approach 2] Using Reversal Algorithm - O(n) Time and O(1) Space

The idea is based on the observation that if we left rotate the array by d positions, the last (n - d) elements will be at the front and the first d elements will be at the end. 

Reverse the subarray containing the first d elements of the array.
Reverse the subarray containing the last (n - d) elements of the array.

Finally, reverse all the elements of the array.</p>

```java
    static void rotateArr(int[] arr, int d) {
        int n = arr.length;
        // Handle the case where d > size of array
        d %= n;
        // Reverse the first d elements
        reverse(arr, 0, d - 1);
        // Reverse the remaining n-d elements
        reverse(arr, d, n - 1);

        // Reverse the entire array
        reverse(arr, 0, n - 1);
    }
    // Function to reverse a portion of the array
    static void reverse(int[] arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
