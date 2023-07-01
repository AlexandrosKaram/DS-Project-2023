#pragma once

#include "Pair.h"
#include "BST.h"

struct AVLNode : public Node {
    int height;   // height of the subtree rooted at this node
};

class AVL : public BST {
protected:
    // override insert method
    void insert(Pair value) override;
    // additional helper methods for AVL tree functionality
    int getHeight(AVLNode* node);
    int getBalance(AVLNode* node);
    void updateHeight(AVLNode* node);
    void rotateLeft(AVLNode*& node);
    void rotateRight(AVLNode*& node);
    void balanceTree(AVLNode*& node);
    void insertNode(AVLNode*& node, Pair value);

public:
    // override showResults method
    void showResults(std::string filename, Pair* Qset, int QsetSize) override;
};