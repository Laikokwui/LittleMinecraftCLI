#pragma once

#include "ListNodeTemplate.h"
#include <iostream>

using namespace std;

template <class T>
class Queue {
public:
    ListNode<T>* fHead; // head node
    ListNode<T>* fTail; // tail node

    // Queue default constructor
    Queue() {
        fHead = nullptr;
        fTail = nullptr;
    }

    // Queue destructor
    ~Queue(){}

    // Queue check is it empty
    bool isEmpty() {
        if (fHead == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

    // Queue add from top and push the down the other node
    void enqueue(const T& aData) {
        ListNode<T>* temp = new ListNode<T>();
        temp->fData = aData;
        temp->fNext = nullptr;
        if (fTail == nullptr) {
            fHead = temp;
            fHead->fNext = fTail;
        }
        else {
            fTail->fNext = temp;
        }
        fTail = temp;
    }

    // Queue remove the first added node
    T dequeue() {
        // If queue is empty, return NULL. 
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        else {
            ListNode<T>* temp = fHead;
            fHead = fHead->fNext;
            return temp->fData;
        }
    }

    // Queue get the head value without dequeue it
    T head() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        else {
            return fHead->fData;
        }
    }

    // Queue get the tail value without dequeue it
    T tail() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        else {
            return fTail->fData;
        }
    }

    // Queue get the size of the queue
    int size() {
        ListNode<T>* temp = fHead;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->fNext;
        }
        return count;
    }
};

