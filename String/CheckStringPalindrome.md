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
```

<p>By Reversing String - O(n) time and O(n) space </p>

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        string cleanStr = "";
        for (char c : s) {
            if (isalnum(c)) {
                cleanStr += tolower(c);
            }
        }
        return cleanStr == string(cleanStr.rbegin(), cleanStr.rend());
    }
};
```

<p>Using Two-Pointers - O(n) time and O(1) space

The idea is to keep two pointers, one at the beginning (left) and the other at the end (right) of the string.

Then compare the characters at these positions. If they don't match, the string is not a palindrome, and return 0.

If they match, the pointers move towards each other (left pointer moves right, right pointer moves left) and continue checking.

If the pointers cross each other without finding a mismatch, the string is confirmed to be a palindrome, and returns 1.</p>


