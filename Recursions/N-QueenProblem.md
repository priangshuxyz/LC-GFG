<p>[Naive Approach] - Using Backtracking Time Complexity: O(n!) Auxiliary Space: O(n2)
<br>The idea is to use backtracking to place queens on an n × n chessboard. We can proceed either row by row or column by column. For each row (or column), try placing a queen in every column (or row) and check if it is safe (i.e., no other queen in the same column, row, or diagonals). If safe, place the queen and move to the next row/column. If no valid position exists, backtrack to the previous step and try a different position. Continue until all queens are placed or all possibilities are explored.</p>

```cpp
int isSafe(vector<vector<int>>& mat, 
                    int row, int col) {
    int n = mat.size();
    int i, j;
    // Check this col on upper side
    for (i = 0; i < row; i++)
        if (mat[i][col])
            return 0;
    // Check upper diagonal on left side
    for (i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j])
            return 0;
    // Check upper diagonal on right side
    for (i = row-1, j = col+1; j < n && i >= 0; i--, j++)
        if (mat[i][j])
            return 0;
    return 1;
}
// Recursive function to place queens
void placeQueens(int row, vector<vector<int>>& mat, vector<vector<int>>&result) {
    int n = mat.size();
    // base case: If all queens are placed
    if(row == n) { 
        // store current solution
        vector<int> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    ans.push_back(j + 1);
                }
            }
        }
        result.push_back(ans);
        return;
    }
    // Consider the row and try placing
    // queen in all columns one by one
    for(int i = 0; i < n; i++){
        // Check if the queen can be placed
        if(isSafe(mat, row, i)){
            mat[row][i] = 1;
            placeQueens(row + 1, mat, result);

            // backtrack
            mat[row][i] = 0; 
        }
    }
}
// Function to find all solutions
vector<vector<int>> nQueen(int n) {
    // Initialize the board
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> result;
    // Place queens
    placeQueens(0, mat, result);
    return result;
}

