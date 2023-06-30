# pragma once

#include "BST.h"

class AVL : public BST {
    public:
    int getHeight(Node*);
    int getBalanceFactor(Node*);
    bool isBalanced(Node*);

    // rotations
    Node* rotateRight(Node*);
    Node* rotateLeft(Node*);
    Node* rightLeftRotate(Node*);
    Node* leftRightRotate(Node*);

    // inserts
    void insertAvlNode(Node*&, Pair value);
    void insert(Pair value);

    void createPairs(std::string filename);
    void searchPairs(Pair* Qset, int QsetSize);
    void showResults(std::string filename, Pair* Qset, int QsetSize);
};