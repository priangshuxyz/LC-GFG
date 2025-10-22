<p>Iterative Method Time Complexity: O(n), where n is the length of the string
Auxiliary Space: O(1) </p>

```java
    public int countVowelSubstrings(String word) {
        int n = word.length();
        int vowelSubstringCount = 0;
        // Use a helper function to check if a char is a vowel
        // This makes the code cleaner to read
        var isVowel = (Character c) -> 
            (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        // Outer loop: iterates through all possible start points of a substring
        for (int i = 0; i < n; i++) {
            // For each new start, reset the set of vowels we've seen
            Set<Character> seenVowels = new HashSet<>();
            // Inner loop: iterates through all possible end points
            for (int j = i; j < n; j++) {
                char c = word.charAt(j);
                // --- Rule 1: Must ONLY contain vowels ---
                if (!isVowel.test(c)) {
                    // If we find a consonant, this substring (and all
                    // other substrings starting at 'i' and ending after 'j')
                    // are invalid. We break the inner loop and move to the next 'i'.
                    break;
                }
                // Add the current vowel to the set for this substring
                seenVowels.add(c);
                // --- Rule 2: Must contain ALL FIVE vowels ---
                if (seenVowels.size() == 5) {
                    // This substring [i...j] is valid!
                    vowelSubstringCount++;
                }
            }
        }
        return vowelSubstringCount;
    }
