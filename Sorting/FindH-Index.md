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

