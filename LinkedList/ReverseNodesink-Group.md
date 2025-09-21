<p>Using Iterative Method – O(n) Time and O(1) Space:
Think of it as the "Cut, Flip, and Connect" method for a chain.
Cut: Your curr pointer moves forward k links to find the section you need to work on. Your groupHead remembers where this section starts.
Flip: You reverse just that small section of the chain.
Connect:
The end of the last section you flipped (tail) connects to the start of the newly flipped section.
You then update your tail to be the end of the section you just flipped, getting it ready for the next connection.</p>

```cpp
Node *reverseKGroup(Node *head, int k) {
    if (head == nullptr) {
        return head;
    }

    Node *curr = head;
    Node *newHead = nullptr;
    Node *tail = nullptr;

    while (curr != nullptr) {
        Node *groupHead = curr;
        Node *prev = nullptr;
        Node *nextNode = nullptr;
        int count = 0;

        // Reverse the nodes in the current group
        while (curr != nullptr && count < k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        // If newHead is null, set it to the
          // last node of the first group
        if (newHead == nullptr) {
            newHead = prev;
        }

        // Connect the previous group to the 
          // current reversed group
        if (tail != nullptr) {
            tail->next = prev;
        }

        // Move tail to the end of the reversed group
        tail = groupHead;
    }

    return newHead;
}

