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
