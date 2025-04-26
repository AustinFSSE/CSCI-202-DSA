

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
