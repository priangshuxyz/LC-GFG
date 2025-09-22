<p>[Naive approach] Using Hashing - O(n) Time and O(n) Space

The idea is to start traversing the Linked List from head node and while traversing insert each node into the HashSet. If there is a loop present in the Linked List, there will be a node which will be already present in the hash set.</p>

```cpp
    unordered_set<Node*> st; 
    Node* currNode = head; 
    // traverse the linked list
    while (currNode != nullptr) {
        // if the current node is already in the HashSet,
        // then this is the starting node of the loop
        if (st.find(currNode) != st.end()) {
            return currNode->data;  
        }
        st.insert(currNode); 
        currNode = currNode->next;
    }
    return -1;
