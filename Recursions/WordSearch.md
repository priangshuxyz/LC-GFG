<p>[Approach] Using Recursion and Backtracking 
<br>Time Complexity: O(n*m * 4k), where n × m is the matrix size and k is the word length
<br>Auxiliary Space: O(k), due to recursion stack depth

The idea is to search for the word in the grid by exploring all possible paths. For every cell that matches the first character of the word, we recursively explore in four directions — up, down, left, and right — to check if the entire word can be formed. We mark cells as visited temporarily during the search to avoid revisiting the same cell in the current path, and backtrack after exploring all possibilities from that cell.</p>

```cpp

// Recursive Function to check if the word exists in the matrix or not
bool findMatch(vector<vector<char>> &mat, string &word, int x, int y, int wIdx) {
    int wLen = word.length();
	int n = mat.size();
  	int m = mat[0].size();
    if (wIdx == wLen)
        return true;
    // Out of Boundary
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;
    // If grid matches with a letter while
    // recursion
    if (mat[x][y] == word[wIdx]) {
        // Marking this cell as visited
        char temp = mat[x][y];
        mat[x][y] = '#';
        // finding subpattern in 4 directions
        bool res = findMatch(mat, word, x - 1, y, wIdx + 1) ||
                   findMatch(mat, word, x + 1, y, wIdx + 1) ||
                   findMatch(mat, word, x, y - 1, wIdx + 1) ||
                   findMatch(mat, word, x, y + 1, wIdx + 1);

        mat[x][y] = temp;
        return res;
    }
    return false;
}
// Function to check if the word exists in the matrix or not
bool isWordExist(vector<vector<char>> &mat, string &word) {
    int wLen = word.length();
	int n = mat.size();
  	int m = mat[0].size();
    // if total characters in matrix is
    // less than word length
    if (wLen > n * m)
        return false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If first letter matches, then recur and check
            if (mat[i][j] == word[0]){
                if (findMatch(mat, word, i, j, 0))
                    return true;
            }
        }
    }
    return false;
}
