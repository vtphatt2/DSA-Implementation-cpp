#include "bst.hpp"

Node* insertBST(Node* &root, int key) {
    if (root == nullptr) {
        root = new Node(key);
        return root;
    }
    if (root->val < key) {
        root->right = insertBST(root->right, key);
    }
    else if (root->val > key) {
        root->left = insertBST(root->left, key);
    }
    return root;
}

void bst::initialize() {
    std::ifstream fin("data.txt");
    int x;
    while (fin >> x) {
        root = insertBST(root, x);
    }
    fin.close();
}

Node* deleteBST(Node* &root) {
    if (root == nullptr) return root;
    delete(root->left);
    delete(root->right);
    delete root;
    root = nullptr;
}

void bst::deleteWholeTree() {
    root = deleteBST(root);
}

void displayLNR_recursive(Node* root) {
    if (root == nullptr) return ;
    displayLNR_recursive(root->left);
    std::cout << (root->val) << " ";
    displayLNR_recursive(root->right);
}

void bst::displayLNR() {
    displayLNR_recursive(root);
}

bool search_recursive(Node* root, int key) {
    if (root != nullptr) {
        if (root->val == key) return true;
        if (root->val < key) return search_recursive(root->right, key);
        else return search_recursive(root->left, key);
    }
    return false;
}

bool bst::search(int key1) {
    return search_recursive(root, key1);
}