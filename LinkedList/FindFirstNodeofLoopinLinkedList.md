<p>[Naive approach] Using Hashing - O(n) Time and O(n) Space

The idea is to start traversing the Linked List from head node and while traversing insert each node into the HashSet. If there is a loop present in the Linked List, there will be a node which will be already present in the hash set.</p>

```cpp
    unordered_set<ListNode*> st;
        ListNode* currNode = head;
        while (currNode != nullptr) {
            if (st.find(currNode) != st.end()) {
                return currNode;
            }
            st.insert(currNode);
            currNode = currNode->next;
        }
        return currNode;
