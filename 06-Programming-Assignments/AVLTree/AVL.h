
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

    public:
    AVL();
    node* rightRotate(node* node);
    node* leftRotate(node* node);

    node* insert(node* node, int key);
    

}