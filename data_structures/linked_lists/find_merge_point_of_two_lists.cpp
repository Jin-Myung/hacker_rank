Node *Reverse(Node *head) {
    Node *ret = nullstr;
    while (head) {
        Node *new_node = new Node;
        new_node->data = head->data;
        if (ret) {
            new_node->next = ret;
        } else {
            new_node->next = nullptr;
        }
        ret = new_node;
        head = head->next;
    }
    return ret;
}
