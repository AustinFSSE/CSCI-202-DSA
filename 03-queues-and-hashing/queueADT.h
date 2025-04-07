//
// Created by Austin Martin on 4/4/25.
//

#pragma once


template <class Type>
class queueADT {

public:
    virtual ~queueADT() = default;

    virtual bool isEmptyQueue() const = 0;
    // Function to determine whether the queue is empty
    // Post-condition: Returns true if the queue is full,
    //                  otherwise returns false.


    virtual bool isFullQueue() const = 0;
    // Function to determine whether the queue is full
    // Post-condition: Returns true if the queue is full,
    //                  otherwise returns false.

    virtual void initializeQueue() = 0;
    // Function to initialize the queue to an empty state.
    // Post-condition: The queue is empty.
    //

    virtual Type front() const = 0;
    // Function to return the first element of the queue.
    // Pre-condition: The queue exists and is not empty
    // Post-condition: If the queue is empty, the program
    //                  terminates; otherwise, the first
    //                  element of the queue is returned

    virtual Type back() const = 0;
    // Function to return the last element of the queue.
    // Pre-condition: The queue exists and is not empty
    // Post-condition: If the queue is empty, the program
    //                 terminates; otherwise, the last
    //                 element of the queue is returned

    virtual void addQueue(const Type& queueElement) = 0;
    // Function to add element to the queue
    // Pre-condition: The queue exists and is not full
    // Post-condition: the queue is changed and
    //                  the queueElement is added to the queue

    virtual void deleteQueue() = 0;
    // Function to remove the first element of the queue.
    // Pre-condition: The queues and is not empty.
    // Post-condition: The queue is changed and
    //                  the first element is removed from the queue

};

