#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
    Node *new_node = new Node;
    new_node->data = data;
    if (nullptr == head) {
        new_node->next = nullptr;
        new_node->prev = nullptr;
        return new_node;
    } else {
        Node *ret = head;
        Node *prev = nullptr;
        while (head && head->data < data) {
            prev = head;
            head = head->next;
        }
        if (nullptr == head) {
            new_node->next = nullptr;
            new_node->prev = prev;
            if (prev) {
                prev->next = new_node;
            }
        } else {
            if (head == ret) {
                ret = new_node;
            }
            new_node->next = head;
            new_node->prev = prev;
            head->prev = new_node;
            if (prev) {
                prev->next = new_node;
            }
        }
        return ret;
    }
}

void printf_ll(Node *head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node *head = nullptr;
    head = SortedInsert(head, 2);
    printf_ll(head);
    head = SortedInsert(head, 1);
    printf_ll(head);
    head = SortedInsert(head, 4);
    printf_ll(head);
    head = SortedInsert(head, 3);
    printf_ll(head);
}
