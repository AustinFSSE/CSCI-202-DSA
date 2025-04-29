#include <iostream>
using namespace std;

// A BTree node
class BTreeNode {
public:
    int* keys;      // Array of keys
    int t;          // Minimum degree (defines range for number of keys)
    BTreeNode** children; // Array of child pointers
    int n;          // Current number of keys
    bool leaf;      // Is true when node is leaf. Otherwise false

    BTreeNode(int _t, bool _leaf);

    void traverse();

    BTreeNode* search(int k);

    void insertNonFull(int k);

    void splitChild(int i, BTreeNode* y);

    friend class BTree;
};

class BTree {
private:
    BTreeNode* root;
    int t;
public:
    BTree(int _t) {
        root = nullptr;
        t = _t;
    }

    void traverse() {
        if (root != nullptr) root->traverse();
    }

    BTreeNode* search(int k) {
        return (root == nullptr) ? nullptr : root->search(k);
    }

    void insert(int k);
};

// Constructor for BTreeNode class
BTreeNode::BTreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;
    keys = new int[2*t-1];
    children = new BTreeNode*[2*t];
    n = 0;
}

// Traverse all nodes in a subtree rooted with this node
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            children[i]->traverse();
        cout << " " << keys[i];
    }

    if (leaf == false)
        children[i]->traverse();
}

// Search key k in subtree rooted with this node
BTreeNode* BTreeNode::search(int k) {
    int i = 0;
    while (i < n && k > keys[i])
        i++;

    if (keys[i] == k)
        return this;

    if (leaf == true)
        return nullptr;

    return children[i]->search(k);
}

// Inserting a new key in a node (assumes node is non-full)
void BTreeNode::insertNonFull(int k) {
    int i = n-1;

    if (leaf == true) {
        while (i >= 0 && keys[i] > k) {
            keys[i+1] = keys[i];
            i--;
        }
        keys[i+1] = k;
        n = n+1;
    }
    else {
        while (i >= 0 && keys[i] > k)
            i--;

        if (children[i+1]->n == 2*t-1) {
            splitChild(i+1, children[i+1]);

            if (keys[i+1] < k)
                i++;
        }
        children[i+1]->insertNonFull(k);
    }
}

// Split the child y of this node at index i
void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->leaf);
    z->n = t-1;

    for (int j = 0; j < t-1; j++)
        z->keys[j] = y->keys[j+t];

    if (y->leaf == false) {
        for (int j = 0; j < t; j++)
            z->children[j] = y->children[j+t];
    }

    y->n = t-1;

    for (int j = n; j >= i+1; j--)
        children[j+1] = children[j];

    children[i+1] = z;

    for (int j = n-1; j >= i; j--)
        keys[j+1] = keys[j];

    keys[i] = y->keys[t-1];
    n = n + 1;
}

// Insert a key into the B-Tree
void BTree::insert(int k) {
    if (root == nullptr) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    else {
        if (root->n == 2*t-1) {
            BTreeNode* s = new BTreeNode(t, false);

            s->children[0] = root;

            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->children[i]->insertNonFull(k);

            root = s;
        }
        else
            root->insertNonFull(k);
    }
}

// Driver program to test above functions
int main() {
    BTree t(3); // A B-Tree with minimum degree 3

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of the constructed tree is: ";
    t.traverse();
    cout << endl;

    int key = 6;
    if (t.search(key) != nullptr)
        cout << "Key " << key << " is found\n";
    else
        cout << "Key " << key << " is not found\n";

    key = 15;
    if (t.search(key) != nullptr)
        cout << "Key " << key << " is found\n";
    else
        cout << "Key " << key << " is not found\n";

    return 0;
}