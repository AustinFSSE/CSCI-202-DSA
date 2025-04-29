
#include <iostream>

using namespace std;

class AVL {

    private:

    struct node {
        int key;
        node* left;
        node* right;
        int height;
    };
    node* root;

    int height(node* node);
    int balanceFactor(node* node);
    node* rightRotate(node* node);
    node* leftRotate(node* node);

    node* insert(node* node, int key);
    bool search(node* root, int key);
    void inorder(node* root);

    public:
    AVL();
    AVL(int key);
    void insert(int key ) { root = insert(root, key); }
    bool search(int key) { return search(root, key); }
    void inorder() { inorder(root); }

};