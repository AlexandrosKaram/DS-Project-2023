# pragma once

#include "Pair.h"

struct Node {
    Pair value;
    Node* left;   // left subtree
    Node* right;   // right subtree
};

class BST {
    protected:
    Node *root;
    double constTime, searchTime;
    int size;
    // protected methods
    virtual void insert(Pair value);
    virtual void createPairs(std::string filename);
    virtual void searchPairs(Pair* Qset, int QsetSize);
    // protected helper methods
    void destroyTree(Node* node);
    void insertNode(Node*& node, Pair value);
    int searchValue(Node* node, Pair value);

    public:
    // constructor - destructor
    BST();
    ~BST();
    // methods
    void showResults(std::string filename, Pair* Qset, int QsetSize);
    void destroyTree();
};