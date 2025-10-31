<p>[Approach] Using Recursion - O(n) time and O(n) space

The idea is to traverse the tree recursively, starting from the root at level 0. When a node is visited, its value is added to the result array at the index corresponding to its level, and then its left and right children are recursively processed in the same way. This effectively performs a level-order traversal using recursion.</p>

```cpp
void levelOrderRec(Node* root, int level, vector<vector<int>>& res) {
    // Base case
    if (root == nullptr) return;

    // Add a new level to the result if needed
    if (res.size() <= level)
        res.push_back({});
  
    // Add current node's data to its corresponding level
    res[level].push_back(root->data);

    // Recur for left and right children
    levelOrderRec(root->left, level + 1, res);
    levelOrderRec(root->right, level + 1, res);
}

// Function to perform level order traversal
vector<vector<int>> levelOrder(Node* root) {
    
    // Stores the result level by level
    vector<vector<int>> res; 
  
    levelOrderRec(root, 0, res);
    return res;
}
```

<p>[Expected Approach] Using Queue (Iterative) - O(n) time and O(n) space
    
The idea is to use a queue to traverse the tree level by level. Start by adding the root to the queue. Then, repeatedly remove a node from the queue, store its value in the result, and add its left and right children to the queue. Continue this process until the queue is empty.</p>

```cpp
// Iterative method to perform level order traversal
vector<vector<int>> levelOrder(Node *root) {
    if (root == nullptr)
        return {};

    // Create an empty queue for level order traversal
    queue<Node *> q;
    vector<vector<int>> res;

    // Enqueue Root
    q.push(root);
    int currLevel = 0;

    while (!q.empty()) {
        int len = q.size();
        res.push_back({});

        for (int i = 0; i < len; i++) {

            // Add front of queue and remove it from queue
            Node *node = q.front();
            q.pop();

            res[currLevel].push_back(node->data);

            // Enqueue left child
            if (node->left != nullptr)
                q.push(node->left);

            // Enqueue right child
            if (node->right != nullptr)
                q.push(node->right);
        }
        currLevel++;
    }
    return res;
}
