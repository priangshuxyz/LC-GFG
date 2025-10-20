<p>Prefix Sum
  
The time complexity is O(n) The space complexity is O(n)</p>

```java
    public int[] runningSum(int[] nums) {
        // Start from index 1 since the first element remains unchanged
        // Each element becomes the sum of itself and all previous elements
        for (int i = 1; i < nums.length; i++) {
            // Add the previous cumulative sum to the current element
            nums[i] = nums[i] + nums[i - 1];
        }
      
        // Return the modified array containing running sums
        return nums;
    }
