

#include <iostream>
#include <cstdlib>

#include "BSTNode.cpp"

using namespace std;

int main() {
    int TreeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};

    BSTNode myTree;

    // cout << "Printing the tree in order\nBefor adding numbers\n";

    // myTree.PrintInOrder();

    for (int i = 0; i < 16; i++) 
    {
        myTree.AddLeaf(TreeKeys[i]);
    }

    // cout << "Printing the tree in order\nAfter adding numbers\n";

    // myTree.PrintInOrder();

    // cout << endl;

    // myTree.PrintChildren(myTree.ReturnRootKey());

    // cout << endl;

    for (int i = 0; i < 16; i++) {
        myTree.PrintChildren(TreeKeys[i]);
        cout << endl;
    }
    
    
    return 0;
}