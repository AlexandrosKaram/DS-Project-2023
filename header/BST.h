# pragma once

#include "Pair.h"
#include "File.h"

class BST {
    protected:
    typedef struct Node {
        Pair value;
        Node *left, *right;
    } Node;
    Node* root;
    // helper methods
    void destroyTree(Node* node);
    void insertNode(Node*& node, Pair value);
    void increaseCount(Node* node, Pair value);

    public:
    // constructor - destructor
    BST();
    ~BST();
    // methods
    void insert(Pair value);
    void search(Pair value);
};