# pragma once

#include "BST.h"

class AVL : public BST {
    public:
    int getHeight(Node*); // gets current height of a tree
    int getBalanceFactor(Node*); // gets the balance factor (height difference between subtrees)
    Node* balance(Node *); // checks if avl is unbalanced.. if yes, it does the needed rotations

    // rotations
    Node* rotateRight(Node*);
    Node* rotateLeft(Node*);
    Node* rightLeftRotate(Node*);
    Node* leftRightRotate(Node*);

    // inserts
    Node* insertAvlNode(Node*, Pair value);
    void insert(Pair value);

    // pairs and results
    void createPairs(std::string filename);
    void searchPairs(Pair* Qset, int QsetSize);
    void showResults(std::string filename, Pair* Qset, int QsetSize);
};