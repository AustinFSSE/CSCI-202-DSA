//
// Created by alm20 on 4/13/2025.
//

#include <algorithm>
#include <ctime>
#include <iostream>
#include <ostream>
#include <random>


class Node {
    public:
    int data;
    Node *next;

   Node (int data) {
        this->data = data;
        next = nullptr;
    }


    void insert(int size, Node *&head) {
       int counter = size;
        Node *current = head;

       std::mt19937 gen(static_cast<unsigned>(time(nullptr)));
       std::uniform_int_distribution<> distribution(0, size*10);

       for (int i = 0; i < size; i++) {

           int randomNumber = distribution(gen);
           current->next = new Node(randomNumber);
           current = current->next;
       }
    }

    void printList(Node *&head) {
       Node *current = head;
       while (current != nullptr) {
           std::cout << current->data << " ";
           current = current->next;
       }
       std::cout << std::endl;
   }
    void selectionSort(Node *&head) {

       for (Node *current = head; current != nullptr; current = current->next) {
           Node *minimum = current;
           for (Node *next = current->next; next != nullptr; next = next->next) {
               if (next->data < minimum->data) {
                   std::swap(next->data, minimum->data);
               }
           }
           if (minimum != current) {
               std::swap(minimum, current);
           }
       }
   }
    Node *split(Node *&head) {
       Node *two_step = head;
       Node *one_step = head;

       while (two_step != nullptr && two_step->next != nullptr) {
           two_step = two_step->next->next;
           if (two_step != nullptr) {
               one_step = one_step->next;
           }
       }
       Node *temp = one_step->next;
       one_step->next = nullptr;
       return temp;
   }
    Node *merge(Node *&first, Node *&second) {
       if (first == nullptr) { return second; }
       if (second == nullptr) { return first; }

       if (first->data < second->data) {

           first->next = merge(first->next, second);
           return first;
       }
       second->next = merge(first, second->next);
       return second;
   }
    Node *mergeSort(Node *&head) {
       if (head == nullptr || head->next == nullptr) { return head; }

       Node *second = split(head);

       head = mergeSort(head);
       second = mergeSort(second);

       return merge(head, second);
   }
};



int main() {
    Node *head = new Node(0);
    Node *anotherHead = new Node(0);
    head->insert(100, head);
    anotherHead->insert(10000, anotherHead);


    // Before
    // head->printList(head);

    // // selection sort
    std::cout << "Running Selection Sort..." << std::endl;
    clock_t begin = clock();
    head->selectionSort(head);
    clock_t finish = clock();
    double doneTime = double(finish-begin)/double(CLOCKS_PER_SEC/1000);
    std::cout << "Selection Sort: " << doneTime << " milliseconds!"<< std::endl;
    //
    // // After
    // head->printList(head);

    // merge sort
    std::cout << "Running Merge Sort..." << std::endl;
    clock_t start = clock();
    anotherHead->mergeSort(anotherHead);
    clock_t end = clock();
    double finishTime = double(end-start)/double(CLOCKS_PER_SEC/1000);
    std::cout << "Merge Sort: " << finishTime << " milliseconds!"<< std::endl;

    // After
    // head->printList(anotherHead);


    return 0;
}