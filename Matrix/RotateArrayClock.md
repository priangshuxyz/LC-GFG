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
```

<p>[Expected Approach 1] Forming Cycles - O(n2) Time and O(1) Space

To solve the question without any extra space, rotate the array in form of cycles. For example, a 4 X 4 matrix will have 2 cycles. The first cycle is formed by its 1st row, last column, last row, and 1st column. The second cycle is formed by the 2nd row, second-last column, second-last row, and 2nd column. The idea is for each square cycle, to swap the elements involved with the corresponding cell in the matrix in an anticlockwise direction i.e. from top to left, left to bottom, bottom to right, and from right to top one at a time using nothing but a temporary variable to achieve this.</p>

```cpp
void rotateMatrix(vector<vector<int>> &mat){
  	int n = mat.size();
  
    // Consider all cycles one by one
    for (int i = 0; i < n / 2; i++) {
      
        // Consider elements in group of 4 
        // as P1, P2, P3 & P4 in current square
        for (int j = i; j < n - i - 1; j++) {
          	//Top-Left corner into a temporary variable.
            int temp = mat[i][j];
//Top-Right corner to the Top-Left corner.
            mat[i][j] = mat[j][n - 1 - i];
//Bottom-Right corner to the Top-Right corner.
            mat[j][n - 1 - i] = mat[n - 1 - i][n - 1 - j];
//Moves the value from the Bottom-Left corner to the Bottom-Right corner.
            mat[n - 1 - i][n - 1 - j] = mat[n - 1 - j][i];
//(from the original Top-Left) to the Bottom-Left corner
            mat[n - 1 - j][i] = temp;
        }
    }
}
```

<p>[Expected Approach 2] Reversing Rows and Transposing - O(n2) Time and O(1) Space
    
Rotating a square matrix 90 degrees counterclockwise, each element moves to a new position. The top row becomes the left most column in reverse order, the second row becomes the second-left most column in reverse order, and so on. By first reversing the rows, you rearrange the elements in such a way that when you transpose them, they end up in their final rotated positions.

<li>Reverse every individual row of the matrix</li>
<li>Perform Transpose of the matrix</li>

<br>Clockwise 90° Rotation: Transpose the matrix, then reverse each row.<br>

Counterclockwise 90° Rotation: Reverse each row, then transpose the matrix.</p>

```cpp
void rotateMatrix(vector<vector<int>> &mat){ 
  	int n = mat.size();
  	
  	// Reverse each row
    for (int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());

    // Performing Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    }
}
