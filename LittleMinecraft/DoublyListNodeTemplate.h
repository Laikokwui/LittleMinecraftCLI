#pragma once

template <class T>
class DoublyListNode {
public:
    T fData; // data
    DoublyListNode* fNext; // next node
    DoublyListNode* fPrev; // previous node

    // Default Constructor
    DoublyListNode() {
        fNext = nullptr;
        fPrev = nullptr;
    }

    // Constructor with one parameter
    DoublyListNode(T aData) {
        fData = aData;
        fNext = nullptr;
        fPrev = nullptr;
    }

    // Destructor
    ~DoublyListNode(){}
};
