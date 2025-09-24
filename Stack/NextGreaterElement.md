<p>[Naive Approach] Using Nested Loops - O(n2) Time and O(1) Space
The idea is to look at all the elements to its right and check if there's a larger element for each element in the array. If we find one, we store it as the next greater element. If no greater element is found, we store -1. This is done using two nested loops: the outer loop goes through each element, and the inner loop searches the rest of the array for a greater element.</p>

```cpp
    int n = arr.size();
    vector<int> res(n, -1);
    // iterate through each element in the array
    for (int i = 0; i < n; i++) {
        // check for the next greater element
        // in the rest of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                res[i] = arr[j];
                break;
            }
        }
    }

    return res;
