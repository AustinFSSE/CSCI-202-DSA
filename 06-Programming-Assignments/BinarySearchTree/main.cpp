
#include <iostream>
#include <cstdlib>

#include "BST.cpp"

using namespace std;

int main() {
    int TreeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};

    BST myTree;
    int input;

    for (int i = 0; i < 16; i++) 
    {
        myTree.AddLeaf(TreeKeys[i]);
    }

    cout << "Printing the tree in order\nAfter adding numbers\n";

    myTree.PrintInOrder();

    cout << endl;

    int totalLeafCount = 0;
    for (int i = 0; i < 16; i++) {
        totalLeafCount += myTree.LeafCount(TreeKeys[i]);
     }
     cout << "Total leaf count is: " << totalLeafCount << endl;

     int totalSingleParent = 0;
     for (int i = 0; i < 16; i++) {
         totalSingleParent += myTree.SingleParent(TreeKeys[i]);
      }
      cout << "Total Single Parent count is: " << totalSingleParent << endl;
}