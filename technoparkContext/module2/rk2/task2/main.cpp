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


    int getMinHeight(Node *root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        if (root->left == nullptr) {
            return getMinHeight(root->right) + 1;
        }
        if (root->right == nullptr) {
            return getMinHeight(root->left) + 1;
        }

        return std::min(getMinHeight(root->left), getMinHeight(root->right)) + 1;
    }


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
    }

    std::cout << binaryTree->getMinHeight(rootNode) << std::endl;


    delete binaryTree;
    return 0;
}

