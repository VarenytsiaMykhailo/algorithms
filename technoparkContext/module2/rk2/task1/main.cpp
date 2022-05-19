#include <iostream>

struct Node {

    int data;

    Node *left = nullptr;

    Node *right = nullptr;

    Node(int value) : data(value) {

    }
};

class BinaryTree {
public:

    BinaryTree(int rootValue) {
        rootNode = new Node(rootValue);
    }

    ~BinaryTree() {
        delete rootNode;
    }

    Node *getRootNode();

    void insert(Node *&node, int value);

    Node *findMinimum(Node *node);

    Node *findMaximum(Node *node);

private:

    Node *rootNode;
};

void BinaryTree::insert(Node *&node, int value) {
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

Node *BinaryTree::findMinimum(Node *node) {
    // assert(node != nullptr);
    if (node != nullptr) {
        while (node->left != nullptr) {
            node = node->left;
        }
    }
    return node;
}

Node *BinaryTree::findMaximum(Node *node) {
    // assert(node != nullptr);
    if (node != nullptr) {
        while (node->right != nullptr) {
            node = node->right;
        }
    }
    return node;
}

Node *BinaryTree::getRootNode() {
    return rootNode;
}




int main() {
    BinaryTree *binaryTree = nullptr;
    Node *rootNode = nullptr;

    int value = 0;
    while (std::cin >> value) {
        if (binaryTree == nullptr) {
            binaryTree = new BinaryTree(value);
            rootNode = binaryTree->getRootNode();
            continue;
        }
        binaryTree->insert(rootNode, value);

        //std::cout << "min = " << binaryTree->findMinimum(rootNode)->data << std::endl;
        //std::cout << "max = " << binaryTree->findMaximum(rootNode)->data << std::endl;
    }

    std::cout << (binaryTree->findMinimum(rootNode)->data == binaryTree->findMaximum(rootNode)->data ? 1 : 0) << std::endl;


    delete binaryTree;
    return 0;
}

