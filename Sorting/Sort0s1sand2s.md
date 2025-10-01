<p>[Naive Approach] Sorting - O(n × log(n)) Time and O(1) Space

The naive solution is to simply sort the array using a standard sorting algorithm or sort library function. This will simply place all the 0s first, then all 1s and 2s at last.</p>

```cpp
sort(arr.begin(), arr.end());
```

<p>[Better Approach] Counting 0s, 1s and 2s - Two Pass

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
