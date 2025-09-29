<p>Input: s1 = "ab", s2 = "eidbaooo"
<br>Output: true
<br>Explanation: s2 contains one permutation of s1 ("ba").</p>
<p>
  Problem: Find if a permutation of string s1 exists as a substring in s2.

Key Idea: Don't check permutations, check character counts. A substring is a permutation if it has the exact same number of each character as s1.

Algorithm: Sliding Window

Create a frequency map (an array of size 26) for s1.

Create another frequency map for the first window of s2 (same size as s1).

Slide the window across s2 one character at a time, updating the window's map in O(1).

If the two maps ever match, return true.

Result: If the loop finishes without a match, return false.

Time Complexity: O(N) where N is the length of s2.

Space Complexity: O(1).
</p>

```cpp
        int n1 = s1.length();
        int n2 = s2.length();
        // Edge case: if s1 is longer than s2, it's impossible.
        if (n1 > n2) {
            return false;
        }
        // Create frequency maps for s1 and the first window of s2.
        vector<int> s1_map(26, 0);
        vector<int> window_map(26, 0);
        // Populate the maps for the first window.
        for (int i = 0; i < n1; ++i) {
            s1_map[s1[i] - 'a']++;
            window_map[s2[i] - 'a']++;
        }
        // Check if the first window is a match.
        if (s1_map == window_map) {
            return true;
        }
        // Slide the window across the rest of s2.
        for (int i = n1; i < n2; ++i) {
            // Add the new character entering the window from the right.
            window_map[s2[i] - 'a']++;
            // Remove the character leaving the window from the left.
            window_map[s2[i - n1] - 'a']--;
            // Check for a match after each slide.
            if (s1_map == window_map) {
                return true;
            }
        }
        // If no match was found after checking all windows.
        return false;
