<p>[Naive Approach - 1] Using Hashing - O(n) Time and O(n) Space
uses a hash map to copy a linked list with random pointers in two passes.
First Pass (Create Nodes): Iterate through the original list. For each old node, create a corresponding new node and store the pair in a hash map (map[old_node] = new_node).
Second Pass (Connect Pointers): Iterate through the original list again. For each old node, use the map to find its corresponding new node and set its pointers:
newNode->next = map[oldNode->next]
newNode->random = map[oldNode->random]</p>

```cpp
    unordered_map<Node*, Node*> mp;
    Node *curr = head;
    // Traverse original linked list to store new 
  	// nodes corresponding to original linked list
    while (curr != nullptr) {
        mp[curr] = new Node(curr->data);
        curr = curr->next;
    }
  	curr = head;
    // Loop to update the next and random pointers 
  	// of new nodes 
    while (curr != nullptr) {
      	mp[curr]->next = mp[curr->next];
      	mp[curr]->random = mp[curr->random];
      	curr = curr->next;
    }
    return mp[head];
```
<p>[Expected Approach] By Inserting Nodes In-place - O(n) Time and O(1) Space
The idea is to create duplicate of a node and instead of storing in a separate hash table, we can insert it in between the original node and the next node. Now, we will have new nodes at alternate positions. 
</p>

```cpp
if (head == nullptr) {
        return nullptr;
    }
    // Create new nodes and insert them next to 
  	// the original nodes
    Node* curr = head;
    while (curr != nullptr) {
        Node* newNode = new Node(curr->data);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }
    // Set the random pointers of the new nodes
    curr = head;
    while (curr != nullptr) {
        if (curr->random != nullptr)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }
    // Separate the new nodes from the original nodes
    curr = head;
    Node* clonedHead = head->next;
    Node* clone = clonedHead;
    while (clone->next != nullptr) {
      	// Update the next nodes of original node 
      	// and cloned node
        curr->next = curr->next->next;
        clone->next = clone->next->next;
      	// Move pointers of original as well as  
      	// cloned linked list to their next nodes
        curr = curr->next;
        clone = clone->next;
    }
    curr->next = nullptr;
    clone->next = nullptr;
    return clonedHead;
