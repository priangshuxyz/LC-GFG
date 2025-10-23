<p>Using Recursion - O(n) time and O(n) space

We can use recursion to check the first and last letters of a string and then recursively check for remaining part of the string.

Base case: if the length of the string is 1 or less, it's considered a palindrome.

If the first and last characters don't match, it's not a palindrome, return 0.

Otherwise, recursively calls itself by incrementing left by 1 and decrementing right by 1</p>

```cpp
class Solution {
public:
    bool isPalindromeUtil(string& s, int left, int right) {
        if (left >= right)
            return 1;
        if (s[left] != s[right])
            return 0;
        return isPalindromeUtil(s, left+1, right-1);
    }

    bool isPalindrome(string s) {
        string cleanStr = "";
        for (char c : s) {
            if (isalnum(c)) {
                cleanStr += tolower(c);
            }
        }
        int left = 0, right = cleanStr.length()-1;
        return isPalindromeUtil(cleanStr,left,right);
    }
};
