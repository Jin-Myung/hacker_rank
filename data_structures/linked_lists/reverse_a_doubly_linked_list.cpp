Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method. 
    Node *rev = nullptr;
    while (head) {
        Node *new_node = new Node;
        new_node->data = head->data;
        new_node->prev = nullptr;
        new_node->next = rev;
        if (rev) {
            rev->prev = new_node;
        }
        rev = new_node;
        head = head->next;
    }
    return rev;
}
