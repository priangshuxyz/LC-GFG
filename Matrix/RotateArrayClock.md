<p>Here are the clockwise 90° rotation versions for all three of your provided approaches.

[Naive Approach] Using Extra Space - O(n²) Time and O(n²) Space
We create a new matrix res. An element at mat[i][j] (source) moves to res[j][n - 1 - i] (destination) for a 90° clockwise rotation. For example, the first row (i=0) becomes the last column (col = n-1-0).</p>

```cpp
void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> res(n, vector<int>(n));
  
    // Rotate the matrix 90 degrees clockwise
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[j][n - 1 - i] = mat[i][j];
        }
    }

    // Copy the rotated matrix back
    // to the original matrix
    mat = res;
}
```

<p>Expected Approach 1] Forming Cycles - O(n²) Time and O(1) Space

This in-place approach swaps the four corners of each "cycle" in a clockwise direction: Top-Left -> Top-Right -> Bottom-Right -> Bottom-Left, and finally Bottom-Left -> Top-Left.</p>

```cpp
void rotateMatrix(vector<vector<int>> &mat){
  	int n = mat.size();
  
    // Consider all cycles one by one
    for (int i = 0; i < n / 2; i++) {
      
        // Consider elements in group of 4
        // for the current square
        for (int j = i; j < n - i - 1; j++) {
          	// Store the Top-Left corner in temp
            int temp = mat[i][j];
            
            // Move Bottom-Left to Top-Left
            mat[i][j] = mat[n - 1 - j][i];
            
            // Move Bottom-Right to Bottom-Left
            mat[n - 1 - j][i] = mat[n - 1 - i][n - 1 - j];
            
            // Move Top-Right to Bottom-Right
            mat[n - 1 - i][n - 1 - j] = mat[j][n - 1 - i];
            
            // Move temp (original Top-Left) to Top-Right
            mat[j][n - 1 - i] = temp;
        }
    }
}
```

<p>[Expected Approach 2] Transposing and Reversing Rows - O(n²) Time and O(1) Space
  
For a 90° clockwise rotation, you first transpose the matrix and then reverse each individual row.</p>

```cpp
#include <algorithm> // Required for std::reverse

void rotateMatrix(vector<vector<int>> &mat){ 
  	int n = mat.size();
  	
  	// 1. Perform Transpose of the matrix
    for (int i = 0; i < n; i++) {
        // Start j from i+1 to only swap the
        // upper triangle with the lower triangle
        for (int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    }

    // 2. Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}
