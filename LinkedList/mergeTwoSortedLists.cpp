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