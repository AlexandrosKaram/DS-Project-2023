#include "../header/BST.h"
#include <iostream>
#include <chrono>

BST:: BST() {
    root = NULL;
}

BST:: ~BST() {
    destroyTree(root);
}

// recursively destroy the tree
void BST:: destroyTree(Node* node) {
    if (node==NULL) return;
    // destroy left subtree
    destroyTree(node->left);
    // destroy right subtree
    destroyTree(node->right);
    // destroy the node itself
    delete node;
}

void BST:: insertNode(Node*& node, Pair value) {
    if (node == NULL)
        node = new Node(value); 
}