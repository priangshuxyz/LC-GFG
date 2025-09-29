<p>Time Complexity: O(n * n!) Auxiliary Space: O(n!)
<br>The idea is to use backtracking to generate all possible permutations of given string s. To do so, first initialize an array of string ans[] to store all the permutations. Start from the 0th index and for each index i, swap the value s[i] with all the elements in its right i.e. from i+1 to n-1, and recur to the index i + 1. If the index i is equal to n, store the resultant string in ans[], else keep operating similarly for all other indices. Thereafter, swap back the values to original values to initiate backtracking. At last sort the array ans[].</p>

```cpp
// Recursive function to generate 
// all permutations of string s
void recurPermute(int index, string &s,
                    vector<string> &ans) {
    // Base Case
    if (index == s.size()) {
        ans.push_back(s);
        return;
    }
    // Swap the current index with all
    // possible indices and recur
    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);
        recurPermute(index + 1, s, ans);
        swap(s[index], s[i]);
    }
}
// Function to find all unique permutations
vector<string> findPermutation(string &s) {
    // Stores the final answer
    vector<string> ans;
    recurPermute(0, s, ans);
    // sort the resultant vector
    sort(ans.begin(), ans.end());
    return ans;
}
```
<p>LC Solution</p>

```cpp
class Solution {
public:
    void backtrack(int idx, vector<int>& nums, vector<vector<int>>& ans) {
        // Base Case: If the index reaches the end, a complete permutation is formed.
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        // Iterate from the current index to the end of the array
        for (int i = idx; i < nums.size(); i++) {
            // 1. Choose: Place the number nums[i] at the current position idx.
            swap(nums[idx], nums[i]);
            // 2. Explore: Recurse for the next position.
            backtrack(idx + 1, nums, ans);
            // 3. Unchoose (Backtrack): Swap back to restore the array.
            swap(nums[idx], nums[i]);
        }
    }
    // The main function that LeetCode calls
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        // Start the backtracking process from the first index (0).
        backtrack(0, nums, ans);
        return ans;
    }
};
