<p>Using backward traversal – O(n) Time and O(n) Space

The idea is to start at the last character of the string and move backward, appending each character to a new string res. This new string res will contain the characters of the original string in reverse order.</p>

```java
string reverseString(string& s) {
    string res; 
  	// Traverse on s in backward direction
  	// and add each charecter to a new string
    for (int i = s.size() - 1; i >= 0; i--) {
        res += s[i];
    }
    return res;
}
