<p>Iterative Method Time Complexity: O(n), where n is the length of the string
Auxiliary Space: O(1) </p>

```java
class Solution {
    public int countVowelSubstrings(String word) {
        int vowelSubstringCount = 0;

        for (int i = 0; i < word.length(); i++) {
            Set<Character> seenVowels = new HashSet<>();
            for (int j = i; j < word.length(); j++) {
                char c = word.charAt(j);

                // Call your simple helper method
                if (!isVowel(c)) {
                    break;
                }
                
                seenVowels.add(c);
                if (seenVowels.size() == 5) {
                    vowelSubstringCount++;
                }
            }
        }
        return vowelSubstringCount;
    }

    // A simple helper function. Easy to read and understand.
    private boolean isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
}
