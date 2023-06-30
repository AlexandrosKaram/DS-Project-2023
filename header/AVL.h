# pragma once

#include "BST.h"

class AVL : public BST {
    protected:
    int getHeight(Node*);
    int getBalanceFactor(Node*);
    bool isBalanced(Node*);
    Node* rotateRight(Node*);
    Node* rotateLeft(Node*);
    Node* insertAvlNode(Node*, Pair value);
};