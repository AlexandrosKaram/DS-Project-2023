# pragma once

#include "BST.h"

class AVL : public BST {
    public:
    int getHeight(Node*);
    int getBalanceFactor(Node*);
    bool isBalanced(Node*);
    Node* rotateRight(Node*);
    Node* rotateLeft(Node*);
    Node* insert(Node*, std::string);
};