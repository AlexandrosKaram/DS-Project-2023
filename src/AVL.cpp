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
    //std::cout<<"rotateRight"<<std::endl;

    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    return newRoot;
}

Node* AVL::rotateLeft(Node* node) {
    //std::cout<<"rotateLeft"<<std::endl;

    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    return newRoot;
}

Node* AVL:: leftRightRotate(Node* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

Node* AVL:: rightLeftRotate(Node* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

void AVL::insertAvlNode(Node*& node, Pair value) {
    //std::cout<<"insertAvlNode"<<std::endl;
    if (!node) {
        node = new Node;
        node->value = value;
        node->value.apps = 1;
        node->left = nullptr;
        node->right = nullptr;
        size++;
    } else if (value == node->value) {
        node->value.apps++;
    } else if (value > node->value) {
        insertAvlNode(node->right, value);
    } else {
        insertAvlNode(node->left, value);
    }

    //std::cout<<"AA"<<std::endl;
    //root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalanceFactor(node);
    ////std::cout<<"BB"<<std::endl;

    if (balance > 1 && node->left && value < node->left->value) { // Right rotation
        //std::cout<<"Right"<<std::endl;
        Node* newRoot = rotateRight(node);

        //root->right = rotateRight(root->right);
        //std::cout<<"endRight"<<std::endl;
    }

    //std::cout<<"E1"<<std::endl;

    if (balance < -1 && node->right && value > node->right->value) { // Left rotation
    //std::cout<<"Left"<<std::endl;
        Node* newRoot = rotateLeft(node);
        //std::cout<<"endLeft"<<std::endl;
    }

    //std::cout<<"E2"<<std::endl;

    if (balance > 1 && node->left && value > node->left->value) { // Left Right rotation
    //std::cout<<"START LF"<<std::endl;
        node->left = rotateLeft(node->left);
        rotateRight(node);
    //std::cout<<"END LF"<<std::endl;
    }

    //std::cout<<"E3"<<std::endl;
    //std::cout<<value<<std::endl;

    if (balance < -1 && node->right && value < node->right->value) { // Right Left rotation
    //std::cout<<"START RL"<<std::endl;
        node->right = rotateRight(node->right);
        rotateLeft(node);
        //std::cout<<"END RL"<<std::endl;
    }

    //std::cout<<"CC"<<std::endl;

    //return node;
}

void AVL:: insert(Pair value) {
    ////std::cout<<"insert"<<std::endl;
    insertAvlNode(root, value);
}


// store unique pairs in the tree
void AVL:: createPairs(std::string filename) {
     std::cout<<"start create"<<std::endl;
    ////std::cout<<"createPairs"<<std::endl;
    std::ifstream file;
    file.open(filename);

    if (file.is_open()) {
        //std::cout<<"A1"<<std::endl;
        auto startConstructing = std::chrono::high_resolution_clock::now();
        std::string word;
        Pair *tempPair = new Pair;
        //std::cout<<"B1"<<std::endl;

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
        //std::cout<<"C1"<<std::endl;

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
    ////std::cout<<"searchPairs"<<std::endl;
    std::cout<<"start search"<<std::endl;
    auto startSearching = std::chrono::high_resolution_clock::now();\

    //std::cout<<"A2"<<std::endl;

    for (int i=0 ; i<QsetSize ; i++) {
        Qset[i].apps = searchValue(root, Qset[i]);
    }

    //std::cout<<"B2"<<std::endl;

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
    //std::cout<<"showResults"<<std::endl;
    createPairs(filename);
    searchPairs(Qset, QsetSize);
}