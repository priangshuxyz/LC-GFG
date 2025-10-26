<p>[Naive Approach] Using Extra Space - O(n^2) Time and O(n^2) Space

We mainly need to move first row elements to first column in reverse order, second row elements to second column in reverse order and so on.</p>

```cpp
void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> res(n, vector<int>(n));
  
    // Rotate the matrix 90 degrees counterclockwise
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[n - j - 1][i] = mat[i][j];
        }
    }

    // Copy the rotated matrix back
    // to the original matrix
    mat = res;
}
