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

Node* Avl::insert(Node* root, int data) {
    if (root == nullptr) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->height = 0;
        return newNode;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        // Duplicate keys are not allowed in AVL tree
        return root;
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalanceFactor(root);

    if (balance > 1 && data < root->left->data) { // Right rotation
        return rotateRight(root);
    }

    if (balance < -1 && data > root->right->data) { // Left rotation
        return rotateLeft(root);
    }

    if (balance > 1 && data > root->left->data) { // Left Right rotation
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && data < root->right->data) { // Right Left rotation
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}