

#pragma once 

class BSTNode {

    private:
        struct node 
        {
            int key;
            node* left;
            node* right;
        };
        node* root;
    
    public:
        BSTNode();
        node* CreateLeaf(int key);
        
};