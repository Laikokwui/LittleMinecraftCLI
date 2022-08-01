#pragma once

#include "DoublyListNodeTemplate.h"
#include <iostream>

using namespace std;

template <class T>
class DoublyLinkedList {
public:
    DoublyListNode<T>* fHead; // head node
    DoublyListNode<T>* fTail; // tail node

    // DoublyLinkedList default constructor
    DoublyLinkedList() {
        fHead = nullptr; // initialise head
        fTail = nullptr; // initialise tail
    }

    // DoublyLinkedList destructor
    ~DoublyLinkedList(){}

    // DoublyLinkedList append as head
    void appendhead(T aData) {
        DoublyListNode<T>* temp; // Create New Node
        temp = new DoublyListNode<T>();
        temp->fData = aData; // insert new node's data
        temp->fPrev = nullptr; // new node fprev point to null
        temp->fNext = fHead; // new node fnext point head node
        // is the List empty?
        if (fHead == nullptr) {
            fTail = temp; // new node become tail
        }
        else {
            fHead->fPrev = temp; // head fprev point to new node
        }
        fHead = temp; // new node becoem head
    }

    // DoublyLinkedList append it after the given node
    void append(DoublyListNode<T>* aNode, T aData) {
        DoublyListNode<T>* temp; // Create New Node
        temp = new DoublyListNode<T>();
        temp->fData = aData; // insert new node's data
        temp->fPrev = aNode; // new node fprev point to given node
        temp->fNext = aNode->fNext; // new node fnext point to given node's fnext
        aNode->fNext = temp; // given node ffrev point to new node
        //is the given node the last node?
        if (aNode->fNext == nullptr) {
            fTail = temp; // new node become tail
        }
    }

    // DoublyLinkedList append before the given node
    void prepend(DoublyListNode<T>* aNode, T aData) {
        DoublyListNode<T>* temp; // Create New Node
        temp = new DoublyListNode<T>();
        temp->fData = aData; // insert new node's data
        temp->fNext = aNode; // new node fnext point to given node
        temp->fPrev = aNode->fPrev; // new node fprev point to given node's fprev
        aNode->fPrev = temp; // given node fprev point to new node
        //is the given node the first node?
        if (aNode->fPrev == nullptr) {
            fHead = temp; // new node become head
        }
    }
    
    // DoublyLinkedList append it as last node
    void appendtail(T aData) {
        DoublyListNode<T>* temp; // Create New Node
        temp = new DoublyListNode<T>();
        temp->fData = aData; // insert new node's data
        temp->fPrev = fTail; // new node fprev point to the tail
        temp->fNext = nullptr; // new node fnext point to null
        //is the list empty?
        if (fTail == nullptr) {
            fHead = temp; // new node become head
        }
        else {
            fTail->fNext = temp; // tail's fnext point to new node
        }
        fTail = temp; // set new node as tail
    }

    // DoublyLinkedList delete the node 
    void remove(DoublyListNode<T>* aNode) {
        // is it the first node?
        if (aNode->fPrev == nullptr) {
            fHead = aNode->fNext; //the next node will be front of list
            fHead->fPrev = nullptr; // head node's fprev point to null
        }
        // is it the last node?
        else if (aNode->fNext == nullptr) {
            fTail = aNode->fPrev; // remove tail node
            fTail->fNext = nullptr; // tail node's fnext point to null
        }
        else {
            aNode->fPrev->fNext = aNode->fNext; //previous node's next will point to current node's next
            aNode->fNext->fPrev = aNode->fPrev; //next node's prev will point to current node's prev
        }
        delete aNode; //delete node
    }

    // DoublyLinkedList print list forward
    void printforward() {
        DoublyListNode<T>* forward; // Create New Node
        forward = fHead; // duplicate the fHead
        // Continue if there are still node
        while (forward != nullptr) {
            cout << forward->fData << " -> "; // Output the Node
            forward = forward->fNext; // Points to next Node
        }
    }

    // DoublyLinkedList print list backward
    void printbackward() {
        DoublyListNode<T>* backward; // Create New Node
        backward = fTail; // duplicate the fTail
        // Continue if there are still node
        while (backward != nullptr) {
            cout << backward->fData << " -> "; // Output the Node
            backward = backward->fPrev; // Points to next Node
        }
    }

    // DoublyLinkedList find node
    DoublyListNode<T>* find(T aData) {
        DoublyListNode<T>* ptr = fHead;
        while (ptr != nullptr) {
            if (ptr->fData == aData) {
                return ptr;
            }
            ptr = ptr->fNext;
        }
        cout << "Cannot be found!" << endl;
        return nullptr;
    }

    // DoublyLinkedList get size
    int size() {
        DoublyListNode<T>* temp = fHead;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->fNext;
        }
        return count;
    }
};
