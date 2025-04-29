

#include "AVL.h"


AVL::AVL() {
    root = NULL;
}

int AVL::height(node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int AVL::balanceFactor(node* node) {

    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

AVL::node* AVL::rightRotate(node* node) {

    AVL::node* x = node->left;
    AVL::node* y = x->right;

    // perform rotation
    x->right = node;
    node->left = y;

    // update heights
    y->height = max(height(y->left), height(y->right) + 1);
    x->height = max(height(x->left), height(x->right) + 1);

    return x;
}

AVL::node* AVL::leftRotate(node* node) {

    AVL::node* x = node->right;
    AVL::node* y = x->left;

    // perform rotation
    x->left  = node;
    node->right = y;

    // return heights
    x->height = max(height(x->left), height(x->right) + 1);
    y->height = max(height(y->left), height(y->right) + 1);

    return x;
}

AVL::node* AVL::insert(node* node, int key) {
    
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    else {
        return node;
    }
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    // check use cases for when balance is less than -1 or greater than 1

    // left left case
    if (balance > 1 && key < node->left->key) { return rightRotate(node); }

    // right right case
    if (balance < -1 && key > node->right->key) { return leftRotate(node);}

    // left right case 
    if (balance > 1 && key > node->left->key) { node->left = leftRotate(node->left); return rightRotate(node); }

    // right left case 
    if (balance < -1 && key < node->right->key) { node->right = rightRotate(node->right); return leftRotate(node);}

    return node;
}

void AVL::inorder(node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << (root->key) << " ";
        inorder(root->right);
    }
}

bool AVL::search(node* root, int key) {
    if (root == nullptr) return false;
    if (root->key == key) return true;
    if (root->key > key) return search(root->left, key);
    return search(root->right, key);
}

AVL::AVL(int key) {
    node* n = new node();
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    n->height = 0;
}
