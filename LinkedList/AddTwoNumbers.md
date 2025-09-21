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
```
<p>[Expected Approach] By storing sum on the longer list - O(m + n) Time and O(1) Space
The idea is to first reverse both linked lists so that addition can be performed starting from the least significant digit. We then iterate through both lists simultaneously, adding corresponding digits along with any carry. For each sum, we create a new node and insert it at the front of the result list.</p>

```cpp
Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        head1 = reverse(head1);
        head2 = reverse(head2);
        Node* sum = nullptr;
        int carry = 0;
        while (head1 != nullptr || head2 != nullptr || carry != 0) {
            int newVal = carry;
            if (head1) {
                newVal += head1->data;
                head1 = head1->next;
            }
            if (head2) {
                newVal += head2->data;
                head2 = head2->next;
            }
            carry = newVal / 10;
            newVal %= 10;
            Node* newNode = new Node(newVal);
            newNode->next = sum;
            sum = newNode;
        }
        while (sum != nullptr && sum->data == 0) {
            Node* temp = sum;
            sum = sum->next;
            delete temp;
        }
        if (sum == nullptr) {
            return new Node(0);
        }
        return sum;
    }
    Node* reverse(Node* head) {
        Node* prev = nullptr, *curr = head, *next;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

