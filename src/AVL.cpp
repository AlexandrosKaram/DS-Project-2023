#include "../header/AVL.h"
#include <iostream>
#include <fstream>
#include <chrono>

void AVL::insert(Pair value) {
    insertNode(reinterpret_cast<AVLNode*&>(root), value);
}

int AVL::getHeight(AVLNode* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int AVL::getBalance(AVLNode* node) {
    if (node == nullptr)
        return 0;
    return getHeight(reinterpret_cast<AVLNode*>(node->left)) - getHeight(reinterpret_cast<AVLNode*>(node->right));
}

void AVL::updateHeight(AVLNode* node) {
    int leftHeight = getHeight(reinterpret_cast<AVLNode*>(node->left));
    int rightHeight = getHeight(reinterpret_cast<AVLNode*>(node->right));
    node->height = 1 + std::max(leftHeight, rightHeight);
}

void AVL::rotateLeft(AVLNode*& node) {
    AVLNode* newRoot = reinterpret_cast<AVLNode*>(node->right);
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);
    node = newRoot;
}

void AVL::rotateRight(AVLNode*& node) {
    AVLNode* newRoot = reinterpret_cast<AVLNode*>(node->left);
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);
    node = newRoot;
}

void AVL::balanceTree(AVLNode*& node) {
    int balance = getBalance(node);
    if (balance > 1) {
        if (getBalance(reinterpret_cast<AVLNode*>(node->left)) < 0)
            rotateLeft(reinterpret_cast<AVLNode*&>(node->left));
        rotateRight(node);
    } else if (balance < -1) {
        if (getBalance(reinterpret_cast<AVLNode*>(node->right)) > 0)
            rotateRight(reinterpret_cast<AVLNode*&>(node->right));
        rotateLeft(node);
    }
    updateHeight(node);
}

void AVL::insertNode(AVLNode*& node, Pair value) {
    if (!node) {
        node = new AVLNode;
        node->value = value;
        node->value.apps = 1;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1;
        size++;
    } else if (value == node->value) {
        node->value.apps++;
    } else if (value > node->value) {
        insertNode(reinterpret_cast<AVLNode*&>(node->right), value);
    } else {
        insertNode(reinterpret_cast<AVLNode*&>(node->left), value);
    }

    balanceTree(node);
}

void AVL::showResults(std::string filename, Pair* Qset, int QsetSize) {
    createPairs(filename);
    searchPairs(Qset, QsetSize);

    // Override the behavior for AVL tree
    std::ofstream output;
    output.open("results/AVL.txt");
    output << "Time to create " << size << " pairs for AVL Tree: " << constTime << " seconds." << std::endl;
    output << "Time to search " << QsetSize << " pairs for AVL Tree: " << searchTime << " seconds." << std::endl;

    output << std::endl << "Pairs and their number of appearances:" << std::endl;
    for (int i = 0; i < QsetSize; i++) {
        output << Qset[i] << std::endl;
    }
}
