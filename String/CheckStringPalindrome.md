<p>Using Recursion - O(n) time and O(n) space

We can use recursion to check the first and last letters of a string and then recursively check for remaining part of the string.

Base case: if the length of the string is 1 or less, it's considered a palindrome.
If the first and last characters don't match, it's not a palindrome, return 0.
Otherwise, recursively calls itself by incrementing left by 1 and decrementing right by 1</p>
