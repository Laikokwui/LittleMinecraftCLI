#pragma once

#include "ListNodeTemplate.h"
#include <iostream>

using namespace std;

template <class T>
class LinkedList {
public:
    ListNode<T>* fHead; // head node
    ListNode<T>* fTail; // tail node

    // linkedlist Default constructor
    LinkedList() {
        fHead = nullptr;
        fTail = nullptr;
    }

    // linkedlist destructor
    ~LinkedList() {}

    // linkedlist check is the list is empty
    bool isEmpty() {
        if (fHead != nullptr) {
            return false;
        }
        else {
            return true;
        }
    }

    // linkedlist add in from head
    void appendhead(T aData) {
        ListNode<T>* temp; // Create New Node
        temp = new ListNode<T>();
        temp->fData = aData; // insert new node's data
        temp->fNext = fHead; // new node fnext point head node
        // is the List empty?
        if (fHead == nullptr) {
            fTail = temp; // new node become tail
        }
        else {
            fHead->fNext = fHead; // head fnext point to itself
            fHead = temp; // head become new node
        }
        fHead = temp; // new node becoem head
    }

    // linkedlist append it after the given node
    void append(ListNode<T>* aNode, T aData) {
        ListNode<T>* temp; // Create New Node
        temp = new ListNode<T>();
        temp->fData = aData; // insert new node's data
        temp->fNext = aNode->fNext; // new node fnext point to given node's fnext
        aNode->fNext = temp; // given node ffrev point to new node
        //is the given node the last node?
        if (aNode->fNext == nullptr) {
            fTail = temp; // new node become tail
        }
    }

    // linkedlist add in from tail
    void appendtail(T aData) {
        ListNode<T>* temp; // Create New Node
        temp = new ListNode<T>();
        temp->fData = aData; // insert new node's data
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

    // linkedlist find the node
    ListNode<T>* find(T aData) {
        ListNode<T>* ptr = fHead;
        while (ptr != nullptr) {
            if (ptr->fData == aData) {
                return ptr;
            }
            ptr = ptr->fNext;
        }
        return nullptr;
    }

    // linkedlist remove node by data
    ListNode<T>* remove(T aData) {
        ListNode<T>* node, ptr;
        node = find(aData);
        ptr = fHead;
        if (ptr == node) {
            ptr->fNext = node->fNext;
            return node;
        }
        else {
            while (ptr->fNext != node) {
                ptr = ptr->fNext;
            }
            ptr->fNext = node->fNext;
            return node;
        }
    }

    // linkedlist print out the list from first to last
    void print() {
        ListNode<T>* ptr = fHead;
        while (ptr != NULL) {
            cout << ptr->fData << endl;
            ptr = ptr->fNext;
        }
        delete ptr;
    }

    // linkedlist get the size of the Singly Linked List
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

