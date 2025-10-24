<p>[Approach] Using Simulation by Visited Matrix - O(m*n) Time and O(m*n) Space

The idea is to simulate the spiral traversal by marking the cells that have already been visited. We can use a direction array to keep track of the movement (right, down, left, up) and change direction when we hit the boundary or a visited cell.

<li>Initialize a 2D array vis[][] to keep track of visited cells.</li>
<li>Use direction arrays dr and dc to represent right, down, left, and up movements.</li>
<li>Start from the top-left cell and follow the direction arrays to visit each cell.</li>
<li>Change direction when encountering a boundary or a visited cell.</li>
<li>Continue until all cells are visited.</li></p>
