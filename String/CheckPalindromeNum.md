<p>[Expected Approach] - By Reversing The Number

Time Complexity : O(d) , where d = log₁₀(n)
Auxiliary space: O(1)

The idea is to find the reverse of the original number and then compare the reversed number with the original number. If the reversed number is same as the original number, the number is palindrome. Otherwise, the number is not a palindrome.  </p>

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        // 1. A negative number is never a palindrome.
        if (x < 0) {
            return false;
        }

        // 2. Use 'long long' to prevent overflow when reversing.
        long long reverse = 0;
        int temp = x; // No need for abs() since we checked for negative

        while (temp != 0) {
            reverse = (reverse * 10) + (temp % 10);
            temp = temp / 10;
        }

        // 3. Compare the long long 'reverse' to the original int 'x'.
        return (reverse == x);
    }
};

