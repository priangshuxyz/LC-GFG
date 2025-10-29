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
```

<p>[Better Approach 2] Sorting and Two-Pointer Technique - O(n × log(n)) time and O(1) space

The idea is to use the two-pointer technique but for using the two-pointer technique, the array must be sorted. Once the array is sorted then we can use this approach by keeping one pointer at the beginning (left) and another at the end (right) of the array. </p>

```cpp
bool twoSum(vector<int> &arr, int target){
  
    sort(arr.begin(), arr.end());

    int left = 0, right = arr.size() - 1;

    // Iterate while left pointer 
    // is less than right
    while (left < right){
        int sum = arr[left] + arr[right];

        // Check if the sum matches the target
        if (sum == target)
            return true;
        else if (sum < target)
        
        // Move left pointer to the right
            left++; 
        else
        
        // Move right pointer to the left
            right--; 
    }
    // If no pair is found
    return false;
}
```

<p>[Expected Approach] Using Hash Set - O(n) time and O(n) space

Hashing provides a more efficient solution to the 2-Sum problem. Rather than checking every possible pair, we store each number in an unordered set during iterating over the array's elements. For each number, we calculate its complement (i.e., target - current number) and check if this complement exists in the set. If it does, we have successfully found the pair that sums to the target. </p>

```cpp
bool twoSum(vector<int> &arr, int target){
  
    // Create an unordered_set to store the elements
    unordered_set<int> s;

    for (int i = 0; i < arr.size(); i++){

        // Calculate the complement that added to
        // arr[i], equals the target
        int complement = target - arr[i];

        // Check if the complement exists in the set
        if (s.find(complement) != s.end())
            return true;

        // Add the current element to the set
        s.insert(arr[i]);
    }
  
    // If no pair is found
    return false;
}
