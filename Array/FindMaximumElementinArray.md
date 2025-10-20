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
