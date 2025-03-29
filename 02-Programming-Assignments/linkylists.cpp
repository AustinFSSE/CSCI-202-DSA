//
// Created by Austin Martin on 3/29/25.
//


#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = new Node();
    head->data = 10;
    head->next = new Node();
    head->next->data = 20;

    cout << head->data << endl;
    cout << head->next << endl;



    return 0;
} // std