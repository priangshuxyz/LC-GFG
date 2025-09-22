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
```
<p>[Expected Approach] Using Floyd's loop detection algorithm - O(n) Time and O(1) Space
This idea is to use Floyd’s Cycle-Finding Algorithm to find a loop in a linked list. After detecting that the loop is present using above algorithm. we will reset the slow pointer to head node and fast pointer will remain at its position. Both slow and fast pointers move one step ahead until fast not equals to slow. The meeting point will be the Starting node of loop.</p>

```cpp
    Node* slow = head;
    Node* fast = head;
    // Traverse the list
    while (fast != nullptr && fast->next != nullptr) {
      	// Move slow pointer by one step
        slow = slow->next;          
      	// Move fast pointer by two steps
        fast = fast->next->next;    
        // Detect loop
        if (slow == fast) {
            // Move slow to head, keep fast at meeting point
            slow = head;
            // Move both one step at a time until they meet
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            // Return the meeting node, which
          	// is the start of the loop
            return slow->data;
        }
    }
    // No loop found
    return -1;
