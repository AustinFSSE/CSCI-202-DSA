
#include <iostream>
#include <cstdlib>
#include "BSTNode.h"



BSTNode::BSTNode() 
{
    root = NULL;
}


BSTNode::node* BSTNode::CreateLeaf(int key) 
{
    node* n = new node;
    n->key = key;
    n->left = NULL;
    n->right = NULL; 
    
    return n;
}


