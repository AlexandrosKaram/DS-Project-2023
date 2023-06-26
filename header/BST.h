# pragma once

#include "Pair.h"

struct Node {
    Pair value;
    Node* left;   // left subtree
    Node* right;   // right subtree
    int height;
};

class BST {
    protected:
    // attributes
    Node *root;
    int size;
    double constTime, searchTime;   // performance
    // protected methods
    void insert(Pair value);
    void createPairs(std::string filename);
    void searchPairs(Pair* Qset, int QsetSize);
    // protected helper methods
    void destroyTree(Node* node);
    virtual void insertNode(Node*& node, Pair value);
    int searchValue(Node* node, Pair value);

    public:
    // constructor - destructor
    BST();
    ~BST();
    // methods
    void showResults(std::string filename, Pair* Qset, int QsetSize);
    void destroyTree();
};