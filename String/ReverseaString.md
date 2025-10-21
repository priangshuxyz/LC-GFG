<p>Using backward traversal – O(n) Time and O(n) Space

The idea is to start at the last character of the string and move backward, appending each character to a new string res. This new string res will contain the characters of the original string in reverse order.</p>

```java
    static String reverseString(String s) {
        StringBuilder res = new StringBuilder();
  
        // Traverse on s in backward direction
        // and add each character to a new string
        for (int i = s.length() - 1; i >= 0; i--) {
            res.append(s.charAt(i));
        }
        return res.toString();
    }
```

<p>Using Two Pointers - O(n) Time and O(1) Space
    
The idea is to maintain two pointers: left and right, such that left points to the beginning of the string and right points to the end of the string. 

While left pointer is less than the right pointer, swap the characters at these two positions. After each swap, increment the left pointer and decrement the right pointer to move towards the center of the string. This will swap all the characters in the first half with their corresponding character in the second half.</p>

```java
string reverseString(string &s) {
    int left = 0, right = s.length() - 1;
    // Swap characters from both ends till we reach
    // the middle of the string
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}
