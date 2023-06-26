#include "../header/Avl.h"

int Avl::getHeight(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    return node->height;
}

int Avl::getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

bool Avl::isBalanced(Node* root) {
    if (root == nullptr) {
        return true;
    }

    int balance = getBalanceFactor(root);

    if (std::abs(balance) > 1) {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

Node* Avl::rotateRight(Node* node) {
    Node* newRoot = node->left;
    Node* temp = newRoot->right;

    newRoot->right = node;
    node->left = temp;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot;
}

Node* Avl::rotateLeft(Node* node) {
    Node* newRoot = node->right;
    Node* temp = newRoot->left;

    newRoot->left = node;
    node->right = temp;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot;
}

Node* Avl::insertNode(Node* root, Pair value) {
    if (root == nullptr) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->height = 0;
        return newNode;
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    } else {
        // Duplicate keys are not allowed in AVL tree
        return root;
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalanceFactor(root);

    if (balance > 1 && value < root->left->value) { // Right rotation
        return rotateRight(root);
    }

    if (balance < -1 && value > root->right->value) { // Left rotation
        return rotateLeft(root);
    }

    if (balance > 1 && value > root->left->value) { // Left Right rotation
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && value < root->right->value) { // Right Left rotation
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}