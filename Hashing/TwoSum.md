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
```

<p>[Better Approach 1] Sorting and Binary Search - O(n × log(n)) time and O(1) space

To check if a pair with a given sum exists in the array, we first sort the array. Then for each element, we compute the required complement (i.e., target - arr[i]) and perform binary search on the remaining subarray (from index i+1 to end) to find that complement.</p>


```cpp
// Function to perform binary search
bool binarySearch(vector<int> &arr, int left,
                          int right, int target){
    while (left <= right){
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return true;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

bool twoSum(vector<int> &arr, int target){
    
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < arr.size(); i++){
        int complement = target - arr[i];

        // Use binary search to 
        // find the complement
        if (binarySearch(arr, i + 1, 
                    arr.size() - 1, complement))
            return true;
    }
  
    // If no pair is found
    return false;
}
