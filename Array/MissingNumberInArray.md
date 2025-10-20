<p>[Naive Approach] Linear Search for Missing Number - O(n^2) Time and O(1) Space

This approach iterates through each number from 1 to n (where n is the size of the array + 1) and checks if the number is present in the array. For each number, it uses a nested loop to search the array. If a number is not found, it is returned as the missing number.</p>

```java
    public static int missingNum(int[] arr) {
        int n = arr.length + 1;
        // Iterate from 1 to n and check
        // if the current number is present
        for (int i = 1; i <= n; i++) {
            boolean found = false;
            for (int j = 0; j < n - 1; j++) {
                if (arr[j] == i) {
                    found = true;
                    break;
                }
            }
            // If the current number is not present
            if (!found)
                return i;
        }
        return -1;
    }
```

<p>[Better Approach] Using Hashing - O(n) Time and O(n) Space

This approach uses a hash array (or frequency array) to track the presence of each number from 1 to n in the input array. It first initializes a hash array to store the frequency of each element. Then, it iterates through the hash array to find the number that is missing (i.e., the one with a frequency of 0).</p>

```java
    public static int missingNum(int[] arr) {
        int n = arr.length + 1;
        // Create hash array of size n+1
        int[] hash = new int[n + 1];
        // Store frequencies of elements
        for (int i = 0; i < n - 1; i++) {
            hash[arr[i]]++;
        }
        // Find the missing number
        for (int i = 1; i <= n; i++) {
            if (hash[i] == 0) {
                return i;
            }
        }
        return -1;
    }
```

<p>[Expected Approach 1] Using Sum of n terms Formula - O(n) Time and O(1) Space

The sum of the first n natural numbers is given by the formula (n * (n + 1)) / 2. The idea is to compute this sum and subtract the sum of all elements in the array from it to get the missing number.</p>

```java
   public static int missingNum(int[] arr) {
        long n = arr.length + 1;
        // Calculate the sum of array elements
        long sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        // Use long for expected sum to avoid overflow
        long expSum = n * (n + 1) / 2;
        // Return the missing number
        return (int)(expSum - sum);
    }
