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
