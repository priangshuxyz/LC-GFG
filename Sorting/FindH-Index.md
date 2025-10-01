<p>[Naive Approach] Using Comparison-based Sorting - O(n × logn) Time and O(1) Space

To find the H-index, you first sort the citation counts in descending order. Then, you iterate through this sorted list, using the index idx to represent the number of papers being considered. As long as the citation count at the current index (citations[idx]) is greater than the index itself, it means you have at least idx + 1 papers with idx + 1 or more citations, so you increment idx. The process stops when you find a paper whose citation count is less than or equal to its index. The final value of idx is the H-index, representing the largest number of papers h that have each been cited at least h times.</p>

```cpp

int hIndex(vector<int> &citations) {
    // sort the citations in descending order
    sort(citations.begin(), citations.end(), greater<int>());
    int n = citations.size();
    int idx = 0;
    // keep incrementing idx till citations[idx] > idx
	while(idx < n && citations[idx] > idx) {
        idx += 1;
    }
    return idx;
}
```

<p>[Expected Approach] Using Counting Sort - O(n) Time and O(n) Space

This method calculates the H-index without sorting by using a frequency counting approach. First, it creates an array to count how many papers have a specific number of citations, capping any citation count greater than the total number of papers, n, at n. Then, it iterates backward from n down to 0, maintaining a running total of papers with at least i citations. The first value i for which this accumulated count is greater than or equal to i is the H-index. This works because by starting from the highest possible value, the first time the condition is met guarantees the largest possible h that satisfies the definition.</p>
```cpp
	int hIndex(vector<int> &citations) {
    int n = citations.size();
    vector<int> freq(n + 1);
    // count the frequency of citations
    for (int i = 0; i < n; i++) {
        if (citations[i] >= n)
            freq[n] += 1;
        else
            freq[citations[i]] += 1;
    }
    int idx = n;
    // variable to keep track of the count of papers
    // having at least idx citations
    int s = freq[n]; 
    while (s < idx) {
        idx--;
        s += freq[idx];
    }
    // return the largest index for which the count of 
    // papers with at least idx citations becomes >= idx
    return idx;
}
