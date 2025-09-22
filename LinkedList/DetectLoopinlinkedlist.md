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
```
<p>[Expected Approach] Using Floyd's Cycle-Finding Algorithm Time Complexity: O(n) Auxiliary Space: O(1)
This idea is to use Floyd's Cycle-Finding Algorithm to find a loop in a linked list. It uses two pointers slow and fast, fast pointer move two steps ahead and slow will move one step ahead at a time.If these pointers meet at the same node then there is a loop.</p>

```cpp
    Node *slow = head, *fast = head;
    // Loop that runs while fast and slow pointer are not
    // nullptr and not equal
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        // If fast and slow pointer points to the same node,
        // then the cycle is detected
        if (slow == fast) {
            return true;
        }
    }
    return false;
