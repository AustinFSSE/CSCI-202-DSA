//
// Created by alm20 on 4/13/2025.
//

#include <algorithm>
#include <ctime>
#include <iostream>
#include <ostream>
#include <random>

// Linked List Node class
class Node {
public:
    int data;
    Node *next;

    // Constructor to initialize a node with a given integer value
    explicit Node(const int data) {
        this->data = data;
        next = nullptr;
    }

    // Insert 'size' number of random elements after the head node
    static void insert(int size, Node *head) {
        Node *current = head;

        // Random number generator setup using Mersenne Twister
        std::mt19937 gen(static_cast<unsigned>(time(nullptr)));
        std::uniform_int_distribution<> distribution(0, size * 10);

        // Generate and insert random integers
        for (int i = 0; i < size; i++) {
            int randomNumber = distribution(gen);
            current->next = new Node(randomNumber);
            current = current->next;
        }
    }

    // Print all elements of the linked list
    static void printList(Node *head) {
        Node *current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Safely deallocate memory used by the linked list
    static void deleteList(Node *head) {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;  // Free each node
        }
    }

    // In-place Selection Sort for linked list (inefficient for large lists)
    static void selectionSort(Node *head) {
        for (Node *current = head; current != nullptr; current = current->next) {
            Node *minimum = current;
            for (Node *next = current->next; next != nullptr; next = next->next) {
                if (next->data < minimum->data) {
                    // Swap values (not nodes) to sort
                    std::swap(next->data, minimum->data);
                }
            }

            // Swap current and minimum if necessary (redundant, but kept from original logic)
            if (minimum != current) {
                std::swap(minimum, current);  // Note: this doesn't affect sorting due to swap of pointers
            }
        }
    }

    // Split the list in half for merge sort using slow/fast pointer technique
    static Node *split(Node *head) {
        Node *two_step = head;   // moves 2 steps at a time
        Node *one_step = head;   // moves 1 step at a time

        // Advance pointers to find the midpoint
        while (two_step != nullptr && two_step->next != nullptr) {
            two_step = two_step->next->next;
            if (two_step != nullptr) {
                one_step = one_step->next;
            }
        }

        // Detach second half of list
        Node *temp = one_step->next;
        one_step->next = nullptr;
        return temp;
    }

    // Merge two sorted linked lists into one sorted list (recursive)
    static Node *merge(Node *first, Node *second) { // NOLINT(*-no-recursion)
        if (first == nullptr) return second;
        if (second == nullptr) return first;

        // Compare nodes and merge recursively
        if (first->data < second->data) {
            first->next = merge(first->next, second);
            return first;
        } else {
            second->next = merge(first, second->next);
            return second;
        }
    }

    // Recursive Merge Sort on a linked list
    static Node *mergeSort(Node *&head) { // NOLINT(*-no-recursion)
        // Base case: 0 or 1 element
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Split list into two halves
        Node *second = split(head);

        // Recursively sort each half
        head = mergeSort(head);
        second = mergeSort(second);

        // Merge the sorted halves
        return merge(head, second);
    }
};


int main() {
    // Initialize two linked lists: one for selection sort, one for merge sort
    auto *head = new Node(0);         // Will use selection sort
    auto *anotherHead = new Node(0);  // Will use merge sort

    // Insert 100 nodes into 'head' and 10,000 nodes into 'anotherHead'
    Node::insert(100, head);
    Node::insert(10000, anotherHead);

    // Run and time Selection Sort
    std::cout << "Running Selection Sort..." << std::endl;
    clock_t begin = clock();
    Node::selectionSort(head);
    clock_t finish = clock();
    double doneTime = static_cast<double>(finish - begin) / static_cast<double>(CLOCKS_PER_SEC / 1000);
    std::cout << "Selection Sort: " << doneTime << " milliseconds!" << std::endl;

    // Run and time Merge Sort
    std::cout << "Running Merge Sort..." << std::endl;
    clock_t start = clock();
    Node::mergeSort(anotherHead);
    clock_t end = clock();
    double finishTime = static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC / 1000);
    std::cout << "Merge Sort: " << finishTime << " milliseconds!" << std::endl;

    // Free memory to avoid leaks
    Node::deleteList(head);
    Node::deleteList(anotherHead);

    return 0;
}
