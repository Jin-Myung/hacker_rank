int get_size(Node *head) {
    int ret = 0;
    while (head) {
        head = head->next;
        ++ret;
    }
    return ret;
}
