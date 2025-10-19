<p>[Naive Approach] Using a temporary array - O(n) Time and O(n) Space

The idea is to use a temporary array to store the reverse of the array.
<li>Create a temporary array of same size as the original array.</li>
<li>Now, copy all elements from original array to the temporary array in reverse order.
</li>
<li>Finally, copy all the elements from temporary array back to the original array.</li> </p>

```java
     static void reverseArray(int[] arr) {
        int n = arr.length;
        // Temporary array to store elements
        // in reversed order
        int[] temp = new int[n];
        // Copy elements from original array
        // to temp in reverse order
        for (int i = 0; i < n; i++)
            temp[i] = arr[n - i - 1];
        // Copy elements back to original array
        for (int i = 0; i < n; i++)
            arr[i] = temp[i];
    }
