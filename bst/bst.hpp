#include <iostream>
#include <fstream>

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int key) {
        val = key;
        left = nullptr;
        right = nullptr;
    }
};

class bst {
    public :
        Node* root = nullptr;
        void initialize();
        void deleteWholeTree();
        void displayLNR();
        bool search(int key);
};