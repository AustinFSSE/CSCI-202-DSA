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

   explicit Node (const int data) {
        this->data = data;
        next = nullptr;
    }


    static void insert(int size, Node *head) {
        Node *current = head;

       std::mt19937 gen(static_cast<unsigned>(time(nullptr)));
       std::uniform_int_distribution<> distribution(0, size*10);

       for (int i = 0; i < size; i++) {

           int randomNumber = distribution(gen);
           current->next = new Node(randomNumber);
           current = current->next;
       }
    }

    static void printList(Node *head) {
       Node *current = head;
       while (current != nullptr) {
           std::cout << current->data << " ";
           current = current->next;
       }
       std::cout << std::endl;
   }
    static void selectionSort(Node *head) {

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
    static Node *split(Node *head) {
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
    static Node *merge(Node *first, Node *second) { // NOLINT(*-no-recursion)
       if (first == nullptr) { return second; }
       if (second == nullptr) { return first; }

       if (first->data < second->data) {

           first->next = merge(first->next, second);
           return first;
       }
       second->next = merge(first, second->next);
       return second;
   }

    static Node *mergeSort(Node *&head) { // NOLINT(*-no-recursion)
       if (head == nullptr || head->next == nullptr) { return head; }

       Node *second = split(head);

       head = mergeSort(head);
       second = mergeSort(second);

       // ReSharper disable once CppDFALocalValueEscapesFunction
       return merge(head, second);
   }
};



int main() {
    auto *head = new Node(0);
    auto *anotherHead = new Node(0);
    Node::insert(100, head);
    Node::insert(10000, anotherHead);

    // // selection sort
    std::cout << "Running Selection Sort..." << std::endl;
    clock_t begin = clock();
    Node::selectionSort(head);
    clock_t finish = clock();
    double doneTime = static_cast<double>(finish - begin)/static_cast<double>(CLOCKS_PER_SEC / 1000);
    std::cout << "Selection Sort: " << doneTime << " milliseconds!"<< std::endl;
    //


    // merge sort
    std::cout << "Running Merge Sort..." << std::endl;
    clock_t start = clock();
    Node::mergeSort(anotherHead);
    clock_t end = clock();
    double finishTime = static_cast<double>(end - start)/static_cast<double>(CLOCKS_PER_SEC / 1000);
    std::cout << "Merge Sort: " << finishTime << " milliseconds!"<< std::endl;


    return 0;
}