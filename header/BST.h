# pragma once

#include "Pair.h"
#include "File.h"

class Node {
    public:
    Pair data;
    Node* left;
    Node* right;
    // constructor 
    Node(Pair value) {this->data = value; left=NULL; right=NULL;}
};
class BST {
    protected:
    Node* root;
    // helper methods
    void destroyTree(Node* node);
    void insertNode(Node*& node, Pair value);
    void increaseCount(Node* node, Pair value);
    // create and search the pairs
    void createPairs(File formatted, Pair* Qset, int QsetSize);
    void searchPairs();

    public:
    // constructor - destructor
    BST();
    ~BST();
    // methods
    void insert(Pair value);
    void search(Pair value);
    void showResults(File formatted, Pair* Qset, int QsetSize);
};