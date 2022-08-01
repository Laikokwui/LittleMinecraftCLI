#pragma once

#include "ListNodeTemplate.h"
#include <iostream>

using namespace std;

template <class T>
class Stack {
public:
    ListNode<T>* fTop; // top node

    // stack default constructor
    Stack() {
        fTop = nullptr;
    }

    // stack destructor
    ~Stack(){}

    // stack check is it empty
    bool isEmpty() {
        if (fTop == nullptr) {
            return true;
        }
        else {
            return false;
        }   
    }

    // stack add from top and push the down the other node
    void push(const T& aData) {
        if (isEmpty()) {
            fTop = new ListNode<T>();
            fTop->fNext = nullptr; 
            fTop->fData = aData;
        }
        else {
            ListNode<T>* temp = new ListNode<T>();
            temp->fData = aData;
            temp->fNext = fTop;
            fTop = temp;
        }
    }

    // stack remove the last added node
    void pop() {
        // check the stack is empty or not
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        }
        else {
            fTop = fTop->fNext; // link the top value to next node value
        }
    }

    // stack get the top value same as peek
    T top() {
        // check stack is empty or not
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return 0;
        }
        else {
            return fTop->fData; // return the top value only
        }
    }

    // stack get the size of the stack
    int size() {
        ListNode<T>* temp = fTop; // copy the top valu
        int count = 0; // count value

        // loop while the node is not null
        while (temp != nullptr) {
            count++;
            temp = temp->fNext; // go to next node
        }

        return count; // return the count
    }
};

