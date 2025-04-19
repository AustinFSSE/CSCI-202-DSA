
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

BSTNode::node* BSTNode::ReturnNode(int key) 
{
    return ReturnNodePrivate(key, root);
}
BSTNode::node* BSTNode::ReturnNodePrivate(int key, node* Ptr) 
{
    if (Ptr != NULL)
    {
        if (Ptr->key == key)
        {
            return Ptr;
        }
        else
        {
            if (key<Ptr->key)
            {
                return ReturnNodePrivate(key, Ptr->left);
            }
            else 
            {
                return ReturnNodePrivate(key, Ptr->right);
            }
        }
    }
    else
    {
        return NULL;
    }
}

int BSTNode::ReturnRootKey()
{
    if ( root != NULL) 
    {
        return root->key;
    }
    else
    {
        return -1000;
    }
}

void BSTNode::PrintChildren(int key) 
{
    node* Ptr = ReturnNode(key);
    if (Ptr != NULL) {
        cout << "Parent Node = " << Ptr->key << endl;

        (Ptr->left == NULL) 
        ?
        cout << "Left Child = NULL\n"
        :
        cout << "Left Child = " << Ptr->left->key << "\n";

        (Ptr->right == NULL) 
        ?
        cout << "Right Child = NULL\n"
        :
        cout << "Right Child = " << Ptr->right->key << "\n";
    } else {
        cout << "Key " << key << " is not in the tree\n";
    }
}

int BSTNode::FindSmallest() {
    return FindSmallestPrivate(root);
}

int BSTNode::FindSmallestPrivate(node* Ptr) {
    if (root == NULL) {
        cout << "The Tree is empty!\n";
        return -1000;
    } else {
        if (Ptr->left != NULL) {
            return FindSmallestPrivate(Ptr->left);
        }
        else {
            return Ptr->key;
        }
    } 
}

void BSTNode::RemoveNode(int key){
    RemoveNodePrivate(key, root);
}

void BSTNode::RemoveNodePrivate(int key, node* parent) {
    if (root != NULL){
        if (root->key == key) {
           RemoveRootMatch(); 
        } else {
            if (key < parent->key && parent->left != NULL) {
                parent->left->key == key 
                ?
                RemoveMatch(parent, parent->left, true)
                :
                RemoveNodePrivate(key, parent->left);
            } else if (key > parent->key && parent->right != NULL) {
                parent->right->key == key 
                ?
                RemoveMatch(parent, parent->right, true)
                :
                RemoveNodePrivate(key, parent->right);
            } else {
                cout << "the key" << key << " was not found in the tree\n";
            }
        }
    } else {
        cout << "the tree is empty\n";
    }
}

void BSTNode::RemoveRootMatch(){
    if (root != NULL) {
        node* delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubtree;

        // Case 0 - 0 children
        if (root->left == NULL && root->right == NULL){
            root = NULL;
            delete delPtr;
        }
        // Case 1 - 1 children
        else if (root->left == NULL && root->right != NULL) {
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
            cout << "the root node with key " << rootKey << " was deleted. " <<
                "The new root contains key " << root->key << endl;
        } else if (root->right == NULL && root->left != NULL) {
            root = root->left;
            delPtr->left = NULL;
            delete delPtr;
            cout << "the root node with key " << rootKey << " was deleted. " <<
                "The new root contains key " << root->key << endl;
        }

        // Case 2 - 2 Children
        else {
            smallestInRightSubtree = FindSmallestPrivate(root->right);
            RemoveNodePrivate(smallestInRightSubtree, root);
            root->key = smallestInRightSubtree;
            cout << "the root key containing key " << rootKey << " was overwritten with key " << root->key << endl;
        }
    } else {
        cout << "The tree is empt\n";
    }
}

void BSTNode::RemoveMatch(node* parent, node* match, bool left) {
    if (root != NULL) {
        node* delPtr;
        int matchKey = match->key;
        int smallestInRightSubTree;

        // Case 0 - 0 Children
        if (match->left == NULL && match->right == NULL) {
            delPtr = match;
            left == true ? parent->left = NULL : parent->right = NULL;
            delete delPtr;
            cout << "the node containing key " << matchKey << " was removed\n";
        }
        // Case 1 - 1 Children
        else if (match->left == NULL && match->right != NULL ) {
            left == true ? parent->left = match->right : parent->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            cout << "the node containing key " << matchKey << " was removed\n";
        }  
        else if (match->left != NULL && match->right == NULL ) {
            left == true ? parent->left = match->left : parent->right = match->left;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            cout << "the node containing key " << matchKey << " was removed\n";
        } 
        // Case 2 - 2 Children
        else {
            smallestInRightSubTree = FindSmallestPrivate(match->right);
            RemoveNodePrivate(smallestInRightSubTree, match);
            match->key = smallestInRightSubTree;
        }
    }
}