#include <iostream>
#include <cassert>

struct Node {

    int data;

    Node *next;

    Node *prev;

    Node() : data(0), next(nullptr), prev(nullptr) {
    }
};

// Worse O(n)
Node *search(Node *head, int a) {
    Node *current = head;
    while (current != nullptr) {
        if (current->data == a) {
            return current;
        }
        current = current->next;
    }
    return 0;
}

// O(1)
Node *insertAfter(Node *node, int a) {
    assert(node != nullptr);
    // Create new Node
    Node *newNode = new Node();
    newNode->data = a;
    newNode->next = node->next;
    newNode->prev = node;
    if (node->next != nullptr) {
        node->next->prev = newNode;
    }
    node->next = newNode;
    return newNode;
}

// O(1)
void deleteAt(Node *node) {
    assert(node != nullptr);
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    }
    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }
    delete node;
}

// O(n), where n - the length of List1
Node *concatLists(Node *head1, Node *head2) {
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }
    Node *tail = head1;
    for (; tail->next != nullptr; tail = tail->next);
    tail->next = head2;
    return head1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
