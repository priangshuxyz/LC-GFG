<p>[Approach] Using Simulation by Visited Matrix - O(m*n) Time and O(m*n) Space

The idea is to simulate the spiral traversal by marking the cells that have already been visited. We can use a direction array to keep track of the movement (right, down, left, up) and change direction when we hit the boundary or a visited cell.

<li>Initialize a 2D array vis[][] to keep track of visited cells.</li>
<li>Use direction arrays dr and dc to represent right, down, left, and up movements.</li>
<li>Start from the top-left cell and follow the direction arrays to visit each cell.</li>
<li>Change direction when encountering a boundary or a visited cell.</li>
<li>Continue until all cells are visited.</li></p>

```cpp
vector<int> spirallyTraverse(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> res;
    vector<vector<bool>> vis(m, vector<bool>(n, false));

    // Arrays to represent the changes 
    // in row and column indices: 
  	// move right(0, +1), move down(+1, 0), 
  	// move left(0, -1), move  up(-1, 0)
  
    // Change in row index for each direction
    vector<int> dr = { 0, 1, 0, -1 };

    // Change in column index for each direction
    vector<int> dc = { 1, 0, -1, 0 };

    // Initial position in the matrix
    int r = 0, c = 0;

    // Initial direction index (0 corresponds to 'right')
    int idx = 0;

    for (int i = 0; i < m * n; ++i) {
        res.push_back(mat[r][c]);
        vis[r][c] = true;

        // Calculate the next cell coordinates based on
        // current direction
        int newR = r + dr[idx];
        int newC = c + dc[idx];

        // Check if the next cell is within bounds and not
        // visited
        if (0 <= newR && newR < m && 0 <= newC && newC < n
            && !vis[newR][newC]) {

            // Move to the next row
            r = newR;

            // Move to the next column
            c = newC;
        }
        else {

            // Change direction (turn clockwise)
            idx = (idx + 1) % 4;

            // Move to the next row according to new
            // direction
            r += dr[idx];

            // Move to the next column according to new
            // direction
            c += dc[idx];
        }
    }
  
    return res;
}
