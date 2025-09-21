<p>[Naive Approach] By creating a new list - O(m + n) Time and O(max(m, n)) Space
Reverse both linked lists.
Use two pointers to traverse them together.
At each step:
Sum the node values + carry.
Create a new node with sum % 10.
Update carry = sum / 10.
If one list ends first, continue with the other plus carry.
If carry remains after the loop, add a final node.
Reverse the resulting linked list to get the final sum.
</p>
```cpp
Node *reverse(Node *head) {
    Node *prev = nullptr, *curr = head, *next;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to trim leading zeros in linked list
Node *trimLeadingZeros(Node* head) {
	while(head->next != nullptr && head->data == 0)
    	head = head->next;
	return head;
}

// Function to add two numbers represented by linked list
Node *addTwoLists(Node *num1, Node *num2) {
    Node *res = nullptr, *curr = nullptr;
    int carry = 0;

	num1 = trimLeadingZeros(num1);
	num2 = trimLeadingZeros(num2);
    num1 = reverse(num1);
    num2 = reverse(num2);

    // Iterate till either num1 is not empty or num2 is
    // not empty or carry is greater than 0
    while (num1 != nullptr || num2 != nullptr || carry != 0) {
        int sum = carry;

        if (num1 != nullptr) {
            sum += num1->data;
            num1 = num1->next;
        }

        if (num2 != nullptr) {
            sum += num2->data;
            num2 = num2->next;
        }
        Node* newNode = new Node(sum % 10);
        carry = sum / 10;

      	// If this is the first node, then make this node
      	// as the head of the resultant linked list
      	if(res == nullptr) {
        	res = newNode;
          	curr = newNode;
        }
      	else {
          	// Append new node to resultant linked list
          	// and move to the next node
        	curr->next = newNode;
        	curr = curr->next;
        }
    }
    return reverse(res);
}
