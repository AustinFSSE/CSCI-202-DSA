//
// Created by alm20 on 4/7/2025.
//

#include "queueADT.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <ostream>

using namespace std;

template <class Type>
struct nodeType{
  Type data;
  nodeType<Type> *link;
};

template <class Type>
class LinkyListQueue : public queueADT<Type> {

  public:
  bool isEmptyQueue() const override;
  bool isFullQueue() const override;
  void initializeQueue() override;
  Type front() const override;
  Type back() const override;
  void addQueue(const Type& item) override;
  void deleteQueue() override;
  void display() const;
  LinkyListQueue& operator=(const LinkyListQueue&);
  LinkyListQueue();
  ~LinkyListQueue();

  private:
    nodeType<Type> *queueFront;
    nodeType<Type> *queueBack;

};

template <class Type>
bool LinkyListQueue<Type>::isEmptyQueue() const {
  return queueFront == nullptr;
}

template <class Type>
bool LinkyListQueue<Type>::isFullQueue() const {
  return false;
}

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

template <class Type>
Type LinkyListQueue<Type>::front() const {
  assert(queueFront != nullptr);
  return queueFront->data;
}

template <class Type>
Type LinkyListQueue<Type>::back() const {
  assert(queueBack != nullptr);
  return queueBack->data;
}

template <class Type>
void LinkyListQueue<Type>::addQueue(const Type& item) {
  nodeType<Type> *temp = new nodeType<Type>;
  temp->data = item;
  temp->link = nullptr;
  if (queueFront == nullptr) {
    queueFront = temp;
    queueBack = temp;
  }
  else {
    queueBack->link = temp;
    queueBack = queueBack->link;
  }
}


template <class Type>
void LinkyListQueue<Type>::deleteQueue() {
  nodeType<Type> *temp;
  if (!isEmptyQueue()) {
    temp = queueFront;
    queueFront = queueFront->link;
    delete temp;
    if (queueFront == nullptr) {
      queueBack = nullptr;
    }
  } else {
    cout << "Queue is empty." << endl;
  }
}


template <class Type>
LinkyListQueue<Type>::LinkyListQueue() {
  queueFront = nullptr;
  queueBack = nullptr;
}

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

template<class Type>
LinkyListQueue<Type>& LinkyListQueue<Type>::operator=(const LinkyListQueue& otherQueue) {

  if (this == &otherQueue) {
    return *this;
  }
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

template<class Type>
LinkyListQueue<Type>::~LinkyListQueue() {
  nodeType<Type> *temp;
  while (queueFront != nullptr) {
    temp = queueFront;
    queueFront = queueFront->link;
    delete temp;
  }
  delete queueBack;
}

int main() {

  LinkyListQueue<int> myQueue;
  int x, y;
  myQueue.initializeQueue();
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

















