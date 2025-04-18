
#include <iostream>
#include <cstdlib>
#include "BSTNode.h"

using namespace std;

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

void BSTNode::AddLeafPrivate(int key, node* Ptr)
{
    if (root == NULL)
    {
        root = CreateLeaf(key);
    } 
    else if (key < Ptr->key) 
    {
        if (Ptr->left != NULL) 
        {
            AddLeafPrivate(key, Ptr->left);
        } 
        else 
        {
            Ptr->left = CreateLeaf(key);
        }
    }
    else if (key > Ptr->key) 
    {
        if (Ptr->right != NULL) 
        {
            AddLeafPrivate(key, Ptr->right);
        } 
        else 
        {
            Ptr->right = CreateLeaf(key);
        }
    }
    else 
    {
        cout << "The key " << key << " has already been added to the tree\n";
    }


}
void BSTNode::AddLeaf(int key) 
{
    AddLeafPrivate(key, root);
}

void BSTNode::PrintInOrder()
{

    PrintInOrderPrivate(root);
}
void BSTNode::PrintInOrderPrivate(node* Ptr)
{
    if (root != NULL)
    {
        if (Ptr->left != NULL) 
        {
            PrintInOrderPrivate(Ptr->left);
        }
        cout << Ptr->key << " ";
        if (Ptr->right != NULL)
        {
            PrintInOrderPrivate(Ptr->right);
        }
    } else { cout << "The tree is empty\n"; }
}

