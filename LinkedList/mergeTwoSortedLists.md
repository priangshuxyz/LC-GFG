<p>[Naive Approach] By Using Array - O((n+m) × log(n+m)) Time and O(n+m) Space  
The idea is to use an array to store all the node data from both linked lists, sort the array, and then construct the resultant sorted linked list from the array elements.</p>

```cpp
Node *sortedMerge(Node *head1, Node *head2) {
    vector<int> arr;

    // pushing the values of the first linked list
    while (head1 != nullptr) {
        arr.push_back(head1->data);
        head1 = head1->next;
    }

    // pushing the values of the second linked list
    while (head2 != nullptr) {
        arr.push_back(head2->data);
        head2 = head2->next;
    }

    // sorting the vector
    sort(arr.begin(), arr.end());

    // creating a new list with sorted values
    Node *dummy = new Node(-1);
    Node *curr = dummy;

    for (int i = 0; i < arr.size(); i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    return dummy->next;
}
```
<p>[Better Approach] Using Recursive Merge - O(n+m) Time and O(n+m) Space
The idea is to pick the smaller head node at each step and let recursion merge the remaining parts. if one list is empty, return the other; otherwise the smaller node becomes the next node in the merged list and its next is the recursive merge of the rest.</p>

```cpp
Node* sortedMerge(Node* head1, Node* head2) {

    // base cases
    if (head1 == nullptr) 
        return head2;
    if (head2 == nullptr) 
        return head1;

    // recursive merging based on smaller value
    if (head1->data <= head2->data) {
        head1->next = sortedMerge(head1->next, head2);
        return head1;
    } else {
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
}
```
