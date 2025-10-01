<p>[Naive Approach] Sorting - O(n × log(n)) Time and O(1) Space

The naive solution is to simply sort the array using a standard sorting algorithm or sort library function. This will simply place all the 0s first, then all 1s and 2s at last.</p>

```cpp
sort(arr.begin(), arr.end());
```

<p>[Better Approach] Counting 0s, 1s and 2s - Two Pass
Time Complexity: O(2 × n), where n is the number of elements in the array
Auxiliary Space: O(1)

A better solution is to traverse the array once and count number of 0s, 1s and 2s, say c0, c1 and c2 respectively. Now traverse the array again, put c0 (count of 0s) 0s first, then c1 1s and finally c2 2s. This solution works in O(n) time, but it is not stable and requires two traversals of the array.</p>

```cpp
    int n = arr.size();
    int c0 = 0, c1 = 0, c2 = 0;
    // count 0s, 1s and 2s
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            c0 += 1;
        else if (arr[i] == 1)
            c1 += 1;
        else
            c2 += 1;
    }
    int idx = 0;
    // place all the 0s
    for (int i = 0; i < c0; i++)
        arr[idx++] = 0;
    // place all the 1s
    for (int i = 0; i < c1; i++)
        arr[idx++] = 1;
    // place all the 2s
    for (int i = 0; i < c2; i++)
        arr[idx++] = 2;
```

<p>[Expected Approach] Dutch National Flag Algorithm - One Pass - O(n) Time and O(1) Space

This sorting approach, known as the Dutch National Flag algorithm, efficiently sorts an array of 0s, 1s, and 2s in a single pass. It uses three pointers—lo, mid, and hi—to partition the array into four sections: all 0s are kept to the left of lo, all 1s between lo and mid, and all 2s to the right of hi. The region between mid and hi contains the unprocessed elements. The algorithm works by iterating with the mid pointer: if arr[mid] is 0, it's swapped with arr[lo] and both pointers advance. If it's a 1, only mid advances. If it's a 2, it's swapped with arr[hi] and hi is decremented. This process continues until the mid pointer surpasses hi, leaving the array fully sorted.</p>

```cpp

    int n = arr.size();
    // initialize three pointers:
    // lo: boundary for 0s
    // mid: current element being checked
    // hi: boundary for 2s
    int lo = 0;
    int hi = n - 1;
    int mid = 0;
    // process elements until mid crosses hi
    while (mid <= hi) {
        if (arr[mid] == 0) {
            // current is 0: swap with lo and move both 
            // pointers forward
            swap(arr[lo++], arr[mid++]);
        }
        else if (arr[mid] == 1) {
            // current is 1: it's already in correct position
            mid++;
        }
        else {
            // current is 2: swap with hi and move hi backward
            // do not increment mid, as swapped value needs
            // to be re-checked
            swap(arr[mid], arr[hi--]);
        }
    }
