#include "../header/AVL.h"
#include "../header/funcs.h"
#include <iostream>
#include <fstream>
#include <chrono>

int AVL::getHeight(Node* node) {
    //std::cout<<"getHeight"<<std::endl;
    if (node == nullptr) {
        return -1;
    }
    return 1 + max(getHeight(node->left),getHeight(node->right));
}

int AVL::getBalanceFactor(Node* node) {
    //std::cout<<"getBalanceFactor"<<std::endl;
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

bool AVL::isBalanced(Node* node) {
    //std::cout<<"isBalanced"<<std::endl;
    if (node == nullptr) {
        return true;
    }

    int balance = getBalanceFactor(node);

    if (std::abs(balance) > 1) {
        return false;
    }

    return isBalanced(node->left) && isBalanced(node->right);
}

Node* AVL::rotateRight(Node* node) {
    //std::cout<<"Rotate Right"<<std::endl;
    Node *t;
    t = node->right;
    node->right = t->left;
    t->left = node;
    return t;
}

Node* AVL::rotateLeft(Node* node) {
    //std::cout<<"Rotate Left"<<std::endl;
    Node *t;
    t = node->left;
    node->left = t->right;
    t->right = node;
    return t;
}

Node* AVL:: leftRightRotate(Node* node) {
    //std::cout<<"Rotate Left Right"<<std::endl;
    Node *t;
    t = node->left;
    node->left = rotateRight(t);
    return rotateLeft(node);
}

Node* AVL:: rightLeftRotate(Node* node) {
    //std::cout<<"Rotate Right Left"<<std::endl;
    Node *t;
    t = node->right;
    node->right = rotateLeft(t);
    return rotateRight(node);
}

Node* AVL::balance(Node* node) {
    //std::cout<<"Balance"<<std::endl;
    int heightDiff = getBalanceFactor(node);
    if (heightDiff > 1) {
        if (getBalanceFactor(node->left) > 0) {
            node = rotateLeft(node);
        } else {
            node = leftRightRotate(node);
        }
    } else if (heightDiff < -1) {
        if (getBalanceFactor(node->right) > 0) {
            node = rightLeftRotate(node);
        } else {
            node = rotateRight(node);
        }
    }
    return node;
}

Node* AVL::insertAvlNode(Node* node, Pair value) {
    //std::cout<<"insertAvlNode"<<std::endl;
    if (!node) {
        node = new Node;
        node->value = value;
        node->value.apps = 1;
        node->left = nullptr;
        node->right = nullptr;
        size++;
        return node;
    } else if (value == node->value) {
        node->value.apps++;
    } else if (value > node->value) {
        node->right = insertAvlNode(node->right, value);
        node = balance(node);
    } else {
        node->left = insertAvlNode(node->left, value);
        node = balance(node);
    }

    return node;
}

void AVL:: insert(Pair value) {
    //std::cout<<"insert"<<std::endl;
    root = insertAvlNode(root, value);
}


// store unique pairs in the tree
void AVL:: createPairs(std::string filename) {
     std::cout<<"start create"<<std::endl;
    ////std::cout<<"createPairs"<<std::endl;
    std::ifstream file;
    file.open(filename);

    if (file.is_open()) {
        
        auto startConstructing = std::chrono::high_resolution_clock::now();
        std::string word;
        Pair *tempPair = new Pair;
        

        // start creating the pairs
        file >> word;
        tempPair->word1 = word;
        while (file) {
            file >> word;
            tempPair->word2 = word;
            insert(*tempPair);
            tempPair->word1 = word;
        }
        delete tempPair;
        

        auto endConstructing = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = endConstructing - startConstructing;
        this->constTime = duration.count();

        file.close();

        std::ofstream output;
        output.open("results/AVL.txt");
        output << "Time to create " << size << " pairs for Binary Search Tree: " << constTime << " seconds." << std::endl; 
    } else {
        std::cerr << "Error! file not found..." << std::endl;
    }
     std::cout<<"end create"<<std::endl;
}

// search the pairs using the custom searchValue function
void AVL:: searchPairs(Pair* Qset, int QsetSize) {
    std::cout<<"start search"<<std::endl;
    auto startSearching = std::chrono::high_resolution_clock::now(); 

    for (int i=0 ; i<QsetSize ; i++) {
        Qset[i].apps = searchValue(root, Qset[i]);
    }

    auto endSearching = std::chrono::high_resolution_clock::now();
    std::chrono::duration <double> duration = endSearching - startSearching;
    searchTime = duration.count();

    std::ofstream output;
    output.open("results/AVL.txt", std::ios::app);
    output << "Time to search " << QsetSize << " pairs for AVL Tree: " << searchTime << " seconds." << std::endl;

    output << std::endl << "Pairs and their number of appearances:" << std::endl;
    for (int i=0 ; i<QsetSize ; i++) {
        output << Qset[i] << std::endl;
    }
     std::cout<<"end search"<<std::endl;
}

void AVL:: showResults(std::string filename, Pair* Qset, int QsetSize) {
    createPairs(filename);
    searchPairs(Qset, QsetSize);
}