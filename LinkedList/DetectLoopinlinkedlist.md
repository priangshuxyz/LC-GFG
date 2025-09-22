<p>[Naive Approach] Using HashSet - O(n) Time and O(n) Space
The idea is to insert the nodes in the Hashset while traversing and whenever a node is encountered that is already present in the hashset (which indicates there's a cycle (loop) in the list) then return true. If the node is NULL, represents the end of Linked List, return false as there is no loop.</p>

```cpp
    unordered_set<Node*>st;
    while (head != nullptr) {
        // if this node is already present
        // in hashmap it means there is a cycle
        if (st.find(head) != st.end())
            return true;
        // if we are seeing the node for
        // the first time, insert it in hash
        st.insert(head);
        head = head->next;
    }
    return false;
