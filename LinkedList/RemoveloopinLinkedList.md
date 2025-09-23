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
```
<p>[Efficient Approach] Using Floyd's Cycle Detection Algorithm - O(n) Time and O(1) Space
Use two pointers, slow and fast and initialize them with the head of the linked list.
Move the fast pointer forward by two nodes and move the slow pointer forward by one node.
If the slow and fast pointer points to the same node, loop is found.
Else if the fast pointer reaches NULL, then no loop is found.
Else repeat the above steps till we reach the end of the linked list or a loop is found.
</p>
<p>Remove Loop in Linked List:
The idea is similar to finding the starting node of Loop in a Linked List. For this, we will point the slow pointer to head node and fast pointer will remain at its position. Both slow and fast pointers move one step ahead until fast->next is not equals to slow->next. When slow->next equals to fast->next we can easily point fast->next to NULL to remove the loop.</p>

```cpp
void removeLoop(Node *head) {
    // If list is empty or has only one node without loop
    if (head == nullptr || head->next ==nullptr)
        return;
    Node *slow = head, *fast = head;
    // Search for loop using slow and fast pointers
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    // If loop exists
    if (slow == fast) {
        slow = head;
        // Case for when the loop starts at the head
        if (slow == fast)
            while (fast->next != slow)
                fast = fast->next;
        // Case for all other loops
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        // since fast->next is the looping point 
        fast->next = nullptr;
    }
}
