<p>[Naive Approach] Using Hashing - O(n) Time and O(n) Space
Check the Set: Before visiting a node, see if it's already in the Hash Set.
If it is, you've found a loop. To break it, set prev.next = null.
If it's not, add the node to the set and continue.
Update Pointers: Move to the next node, and update prev to point to the node you just left.
If you reach the end of the list (null), there was no loop.</p>

```cpp
    unordered_set<Node *> st;
    // pointer to prev node
    Node *prev = nullptr;
    while (head != nullptr) {
        // if node not present in the map,
        // insert it in the map
        if (st.find(head) == st.end()) {
            st.insert(head);
            prev = head;
            head = head->next;
        }
        // if present, it is a cycle, make
        // last node's next pointer NULL
        else {
            prev->next = nullptr;
            break;
        }
    }
