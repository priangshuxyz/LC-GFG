<p>[Naive Approach] Generating all Possible Pairs - O(n2) time and O(1) space

The basic approach is to generate all the possible pairs and check if any of them add up to the target value.</p>


```cpp
bool twoSum(vector<int> &arr, int target) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
      
        // For each element arr[i], check every
        // other element arr[j] that comes after it
        for (int j = i + 1; j < n; j++) {
          
            // Check if the sum of the current pair
            // equals the target
            if (arr[i] + arr[j] == target) {
                return true;
            }
        }
    }
  
    // If no pair is found after checking
    // all possibilities
    return false;
}
