<p>[Expected Approach] - By Reversing The Number

Time Complexity : O(d) , where d = log₁₀(n)
Auxiliary space: O(1)

The idea is to find the reverse of the original number and then compare the reversed number with the original number. If the reversed number is same as the original number, the number is palindrome. Otherwise, the number is not a palindrome.  </p>

```cpp
bool isPalindrome(int n) {
    int reverse = 0;
    // Copy of the original number so that the original
    // number remains unchanged while finding the reverse
    int temp = abs(n);
    while (temp != 0) {
        reverse = (reverse * 10) + (temp % 10);
        temp = temp / 10;
    }   
    // If reverse is equal to the original number,
    // the number is palindrome
    return (reverse == abs(n));
}

