//
// Created by Austin Martin on 4/4/25.
//


#include "queueADT.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <ostream>

template <class Type>
class queueType: public queueADT<Type> {
    public:
    bool isEmptyQueue() const override;
    bool isFullQueue() const override;
    void initializeQueue() override;
    Type front() const override;
    Type back() const override;
    void addQueue(const Type& item) override;
    void deleteQueue() override;
    void display() const;
    queueType& operator=(const queueType&);
    queueType(int capacity);
    ~queueType();



private:
    int count = 0;
    int maxQueueSize = 0;
    int queueFront = 0;
    int queueRear = 0;
    Type *list;

};
template<class Type>
bool queueType<Type>::isEmptyQueue() const {
    return count == 0;
}
template<class Type>
bool queueType<Type>::isFullQueue() const {
    return count == maxQueueSize;
}

template<class Type>
void queueType<Type>::initializeQueue() {
    count = 0;
    queueFront = 0;
    queueRear = maxQueueSize - 1;
    list = new Type[maxQueueSize];
}

template<class Type>
Type queueType<Type>::front() const {
    assert(count != 0);
    return list[queueFront];
}

template<class Type>
Type queueType<Type>::back() const {
    assert(count != 0);
    return list[queueRear];
}

template<class Type>
void queueType<Type>::addQueue(const Type &item) {
    if (!isFullQueue()) {
        queueRear = (queueRear + 1) % maxQueueSize;

        count++;
        list[queueRear] = item;
    } else {
        std::cout << "Queue is full" << std::endl;
    }
}

template<class Type>
void queueType<Type> :: deleteQueue() {
    if (!isEmptyQueue()) {
        count--;
        queueFront = (queueFront + 1) % maxQueueSize;
    } else {
        std::cout << "Queue is empty." << std::endl;
    }
}

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

template<class Type>
queueType<Type>::~queueType() {
    delete[] list;
}

template<class Type>
void queueType<Type>::display() const {
    assert(count != 0);
    for (int i = 0; i < count; i++) {
        int index = (queueFront + i) % maxQueueSize;
        std::cout << list[index] << " ";
    }
    std::cout << std::endl;
}

template<class Type>
queueType<Type> &queueType<Type>::operator=(const queueType<Type>& otherType) {
    // check for self-assignment
    if (this != &otherType) {
        delete[] list;

        // copy the metadata
        maxQueueSize = otherType.maxQueueSize;
        count = otherType.count;
        queueFront = otherType.queueFront;
        queueRear = otherType.queueRear;

        // create a new memory address
        list = new Type[maxQueueSize];

        // copy elements from other to current queue
        for (int i = 0; i < count; i++) {
            list[i] = otherType.list[i];
        }
    }
    return *this;
}




int main() {

    // set up the queues
    queueType<int> q1(5);
    queueType<int> q2(5);
    q1.addQueue(10);
    q1.addQueue(20);
    q1.addQueue(30);
    q1.addQueue(40);
    q1.addQueue(50);
    // q1.display();

    std::cout << q1.front() << std::endl;
    std::cout << q1.back() << std::endl;
    q1.display();


    q1.deleteQueue();
    q1.display();

    // display the operator effect
    q2 = q1;
    q2.display();
}
