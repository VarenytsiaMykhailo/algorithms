#include <iostream>
#include <cassert>

struct Node {

    // TODO

    int data;

    Node *left = nullptr;

    Node *right = nullptr;

    Node(int value) : data(value) {

    }
};

// Get Node associated with the value (key). Recursive realisation
Node *find(Node *node, int value) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->data == value) {
        return node;
    }
    if (node->data > value) {
        return find(node->left, value);
    } else {
        return find(node->right, value);
    }
}

// Get Node with the minimum value (key)
Node *findMinimum(Node *node) {
    // assert(node != nullptr);
    if (node != nullptr) {
        while (node->left != nullptr) {
            node = node->left;
        }
    }
    return node;
}

// Get Node with the maximum value (key)
Node *findMaximum(Node *node) {
    // assert(node != nullptr);
    if (node != nullptr) {
        while (node->right != nullptr) {
            node = node->right;
        }
    }
    return node;
}

// Recursive realisation
void insert(Node *&node, int value) {
    if (node == nullptr) {
        node = new Node(value);
        return;
    }
    if (node->data > value) {
        insert(node->left, value);
    } else {
        insert(node->right, value);
    }
}

void deleteNodeHelper(Node *&node) {
    if (node->left == nullptr) { // If there is no left subtree
        Node *right = node->right;
        delete node;
        node = right;
    } else if (node->right == nullptr) { // If there is no right subtree
        Node *left = node->left;
        delete node;
        node = left;
    } else { // If left and right subtrees exist
        // Find min elem in the right subtree and its parent
        Node *minParent = node;
        Node *min = node->right;
        while (min->left != nullptr) {
            minParent = min;
            min = min->left;
        }
        // Move data
        node->data = min->data;

        (minParent->left == min ? minParent->left : minParent->right) = min->right;
        delete min;
    }
}

// Delete node associated with the value (key). Returns false if there is no Node. Recursive realisation
bool deleteNode(Node *&node, int value) {
    if (node == nullptr) {
        return false;
    }
    if (node->data == value) { // Found the Node
        deleteNodeHelper(node);
        return true;
    }
    return deleteNode(node->data > value ? node->left : node->right, value);
}

// Get num of elems in subtree. Recursive realisation
int countSubtreeElems(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    return countSubtreeElems(node->left) + countSubtreeElems(node->right) + 1;
}

int main() {
    Node *rootNode = new Node(12312);
    std::cout << rootNode << std::endl;

    insert(rootNode, 333);
    std::cout << rootNode << std::endl;

    std::cout << find(rootNode, 333)->data << std::endl;

    std::cout << findMinimum(rootNode)->data << std::endl;
    std::cout << findMaximum(rootNode)->data << std::endl;
    std::cout << countSubtreeElems(rootNode) << std::endl;

    std::cout << "After delete:" << std::endl;
    deleteNode(rootNode, 12312);
    std::cout << rootNode << std::endl;

    std::cout << find(rootNode, 12312) << std::endl;
    std::cout << find(rootNode, 333)->data << std::endl;

    std::cout << findMinimum(rootNode)->data << std::endl;
    std::cout << findMaximum(rootNode)->data << std::endl;
    std::cout << countSubtreeElems(rootNode) << std::endl;

    return 0;
}
