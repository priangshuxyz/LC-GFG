<p>Iterative Approach - O(n) Time and O(1) Space
  
The approach to solve this problem is to traverse the whole array and find the maximum among them.</p>

```java
 static int largest(int[] arr) {
        int max = arr[0];
        // Traverse array elements from second and
        // compare every element with current max
        for (int i = 1; i < arr.length; i++)
            if (arr[i] > max)
                max = arr[i];
        return max;
    }
```

<p>Recursive Approach - O(n) Time and O(n) Space
  
The idea is similar to the iterative approach. Here the traversal of the array is done recursively instead of an iterative loop. </p>

```java
    static int findMax(int[] arr, int i) {
        // Last index returns the element
        if (i == arr.length - 1) {
            return arr[i];
        }
        // Find the maximum from the rest of the array
        int recMax = findMax(arr, i + 1);

        // Compare with i-th element and return
        return Math.max(recMax, arr[i]);
    }
    static int largest(int[] arr) {
        return findMax(arr, 0);
    }
```

<p>Using Library Methods - O(n) Time and O(1) Space</p>

```java
     static int largest(int[] arr) {
        Arrays.sort(arr);
        return arr[arr.length - 1];
    }
