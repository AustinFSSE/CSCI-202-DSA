//
// Created by Austin Martin on 4/4/25.
//

#include "queueADT.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <ostream>

// queueType is a templated class that implements a circular queue
template <class Type>
class queueType: public queueADT<Type> {
public:
    // Check if queue is empty
    [[nodiscard]] bool isEmptyQueue() const override;

    // Check if queue is full
    [[nodiscard]] bool isFullQueue() const override;

    // Reset the queue to an empty state
    void initializeQueue() override;

    // Return the element at the front of the queue
    Type front() const override;

    // Return the element at the back of the queue
    Type back() const override;

    // Add a new item to the rear of the queue
    void addQueue(const Type& item) override;

    // Remove the item at the front of the queue
    void deleteQueue() override;

    // Print the contents of the queue
    void display() const;

    // Overloaded assignment operator
    queueType& operator=(queueType&);

    // Constructor to initialize the queue with a given capacity
    queueType(int capacity);

    // Destructor to deallocate memory
    ~queueType();

private:
    int count = 0;              // Number of elements currently in the queue
    int maxQueueSize = 0;       // Maximum size of the queue
    int queueFront = 0;         // Index of the front of the queue
    int queueRear = 0;          // Index of the rear of the queue
    Type *list;                 // Dynamic array to store queue elements
};

// Return true if there are no elements in the queue
template<class Type>
bool queueType<Type>::isEmptyQueue() const {
    return count == 0;
}

// Return true if the queue is at maximum capacity
template<class Type>
bool queueType<Type>::isFullQueue() const {
    return count == maxQueueSize;
}

// Reset queue to an empty state and allocate memory
template<class Type>
void queueType<Type>::initializeQueue() {
    count = 0;
    queueFront = 0;
    queueRear = maxQueueSize - 1;
    list = new Type[maxQueueSize];
}

// Return the element at the front of the queue
template<class Type>
Type queueType<Type>::front() const {
    assert(count != 0);  // Ensure the queue is not empty
    return list[queueFront];
}

// Return the element at the back of the queue
template<class Type>
Type queueType<Type>::back() const {
    assert(count != 0);  // Ensure the queue is not empty
    return list[queueRear];
}

// Add an item to the rear of the queue
template<class Type>
void queueType<Type>::addQueue(const Type &item) {
    if (!isFullQueue()) {
        queueRear = (queueRear + 1) % maxQueueSize; // Circular increment
        count++;
        list[queueRear] = item; // Insert item
    } else {
        std::cout << "Queue is full" << std::endl;
    }
}

// Delete the front item of the queue
template<class Type>
void queueType<Type>::deleteQueue() {
    if (!isEmptyQueue()) {
        count--;
        queueFront = (queueFront + 1) % maxQueueSize; // Circular increment
        display();
    } else {
        std::cout << "Queue is empty." << std::endl;
    }
}

// Constructor: create a queue with the specified capacity
template<class Type>
queueType<Type>::queueType(int capacity) {
    if (capacity <= 0) {
        std::cout << "Capacity must be greater than 0." << std::endl;
        std::cout << "Creating an array the size of 100" << std::endl;
        maxQueueSize = 100;
    } else {
        maxQueueSize = capacity;
    }

    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
    list = new Type[maxQueueSize];
}

// Destructor: deallocates the dynamic array
template<class Type>
queueType<Type>::~queueType() {
    delete[] list;
}

// Display the current elements in the queue from front to rear
template<class Type>
void queueType<Type>::display() const {
    assert(count != 0);
    for (int i = 0; i < count; i++) {
        int index = (queueFront + i) % maxQueueSize; // Circular indexing
        std::cout << list[index] << " ";
    }
    std::cout << std::endl;
}

// Overloaded assignment operator to copy contents from another queue
template<class Type>
queueType<Type>& queueType<Type>::operator=(queueType& otherType) {
    // Check for self-assignment
    if (this != &otherType) {
        delete[] list; // Free current memory

        // Copy metadata
        maxQueueSize = otherType.maxQueueSize;
        count = otherType.count;
        queueFront = otherType.queueFront;
        queueRear = otherType.queueRear;

        // Allocate new memory and copy elements
        list = new Type[maxQueueSize];
        for (int i = 0; i < count; i++) {
            list[i] = otherType.list[i];
        }
    }
    return *this;
}

// ---------------- Main Driver Program -----------------

int main() {
    // Create two queue objects with capacity 5
    queueType<int> q1(5);
    queueType<int> q2(5);

    // Add elements to q1
    q1.addQueue(10);
    q1.addQueue(20);
    q1.addQueue(30);
    q1.addQueue(40);
    q1.addQueue(50);
    std::cout << "Displaying Queue: " << std::endl;
    q1.display();

    std::cout << std::endl;

    // Display front and back elements
    std::cout << "Front of queue: "<< q1.front() << std::endl;
    std::cout << "Back of queue: " <<q1.back() << std::endl;

    std::cout << std::endl;

    // Remove the front element and display updated queue
    q1.display();
    std::cout << "Deleting first element " << std::endl;
    q1.deleteQueue();

    std::cout << std::endl;

    // Demonstrate assignment operator: copy q1 to q2
    q2 = q1;
    q2.display();

    return 0;
}
