#include "AVL.cpp"
#include <iostream>


int main()
{
    AVL avl;

    // Insert nodes into the AVL tree
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    // Print the inorder traversal of the AVL tree
    cout << "Inorder traversal of the AVL tree: ";
    avl.inorder();

    // Search for nodes in the AVL tree
    cout << "Is 25 in the tree? "
         << (avl.search(25) ? "Yes" : "No") << endl;
    cout << "Is 30 in the tree? "
         << (avl.search(30) ? "Yes" : "No") << endl;
    
         

    return 0;
}