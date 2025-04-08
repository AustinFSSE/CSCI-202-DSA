//
// Created by alm20 on 4/7/2025.
//

#include "queueADT.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <ostream>

using namespace std;

// Node definition for the linked list queue
template <class Type>
struct nodeType {
    Type data;
    nodeType<Type> *link; // Pointer to the next node
};

// Linked List–based Queue class inheriting from queueADT
template <class Type>
class LinkyListQueue : public queueADT<Type> {
public:
    bool isEmptyQueue() const override;  // Check if queue is empty
    bool isFullQueue() const override;   // Check if queue is full (always false in linked list)
    void initializeQueue() override;     // Clears the queue
    Type front() const override;         // Returns the front element
    Type back() const override;          // Returns the back element
    void addQueue(const Type& item) override; // Adds item to the queue
    void deleteQueue() override;         // Removes item from the front of the queue
    void display() const;                // Prints all elements in the queue
    LinkyListQueue& operator=(const LinkyListQueue&); // Copy assignment operator
    LinkyListQueue();                    // Constructor
    ~LinkyListQueue() override;          // Destructor

private:
    nodeType<Type> *queueFront; // Points to the front node
    nodeType<Type> *queueBack;  // Points to the back node
};

// Returns true if the queue is empty
template <class Type>
bool LinkyListQueue<Type>::isEmptyQueue() const {
    return queueFront == nullptr;
}

// Linked list queue is never full unless memory is exhausted
template <class Type>
bool LinkyListQueue<Type>::isFullQueue() const {
    return false;
}

// Clears the queue by deleting all nodes
template <class Type>
void LinkyListQueue<Type>::initializeQueue() {
    nodeType<Type> *temp;
    while (queueFront != nullptr) {
        temp = queueFront;
        queueFront = queueFront->link;
        delete temp;
    }
    queueBack = nullptr;
}

// Returns the data at the front node
template <class Type>
Type LinkyListQueue<Type>::front() const {
    assert(queueFront != nullptr); // Make sure queue isn't empty
    return queueFront->data;
}

// Returns the data at the back node
template <class Type>
Type LinkyListQueue<Type>::back() const {
    assert(queueBack != nullptr); // Make sure queue isn't empty
    return queueBack->data;
}

// Adds a new element to the back of the queue
template <class Type>
void LinkyListQueue<Type>::addQueue(const Type& item) {
    nodeType<Type> *temp = new nodeType<Type>;
    temp->data = item;
    temp->link = nullptr;

    if (queueFront == nullptr) {
        // Queue is empty
        queueFront = temp;
        queueBack = temp;
    } else {
        // Append to the end and update queueBack
        queueBack->link = temp;
        queueBack = queueBack->link;
    }
}

// Removes the front node from the queue
template <class Type>
void LinkyListQueue<Type>::deleteQueue() {
    nodeType<Type> *temp;
    if (!isEmptyQueue()) {
        temp = queueFront;
        queueFront = queueFront->link;
        delete temp;

        // If we removed the last element
        if (queueFront == nullptr) {
            queueBack = nullptr;
        }
    } else {
        cout << "Queue is empty." << endl;
    }
}

// Constructor initializes both front and back to nullptr
template <class Type>
LinkyListQueue<Type>::LinkyListQueue() {
    queueFront = nullptr;
    queueBack = nullptr;
}

// Displays all elements in the queue
template<class Type>
void LinkyListQueue<Type>::display() const {
    nodeType<Type> *temp;
    if (!isEmptyQueue()) {
        temp = queueFront;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }
}

// Copy assignment operator: clears current queue and copies from another queue
template<class Type>
LinkyListQueue<Type>& LinkyListQueue<Type>::operator=(const LinkyListQueue& otherQueue) {
    if (this == &otherQueue) return *this;

    while (!isEmptyQueue()) {
        deleteQueue();
    }

    nodeType<Type> *temp = otherQueue.queueFront;
    while (temp != nullptr) {
        addQueue(temp->data);
        temp = temp->link;
    }

    return *this;
}

// Destructor deallocates all nodes
template<class Type>
LinkyListQueue<Type>::~LinkyListQueue() {
    nodeType<Type> *temp;
    while (queueFront != nullptr) {
        temp = queueFront;
        queueFront = queueFront->link;
        delete temp;
    }
}

// Demonstrates queue functionality
int main() {
    LinkyListQueue<int> myQueue;
    int x, y;

    myQueue.initializeQueue(); // Clear queue (if needed)
    x = 10;
    y = 50;

    myQueue.addQueue(x);
    myQueue.addQueue(y);

    cout << "Displaying Queue: ";
    myQueue.display();

    cout << "Peeking at the front: ";
    x = myQueue.front();
    cout << x << endl;

    cout << "Deleting front: ";
    myQueue.deleteQueue();
    myQueue.display();

    cout << "Adding x + 7 back into the queue: ";
    myQueue.addQueue(x + 7);
    myQueue.display();

    myQueue.addQueue(88);
    myQueue.addQueue(x);
    myQueue.addQueue(y + 1999);
    cout << "Displaying Queue:  (50, 17) adding 88, x, y + 1999" << endl;
    myQueue.display();

    return 0;
}
