<p>[Approach] Using Recursion and Backtracking 
<br>Time Complexity: O(n*m * 4k), where n × m is the matrix size and k is the word length
<br>Auxiliary Space: O(k), due to recursion stack depth
<br>The idea is to search for the word in the grid by exploring all possible paths. For every cell that matches the first character of the word, we recursively explore in four directions — up, down, left, and right — to check if the entire word can be formed. We mark cells as visited temporarily during the search to avoid revisiting the same cell in the current path, and backtrack after exploring all possibilities from that cell.</p>
