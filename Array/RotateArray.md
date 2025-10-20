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
