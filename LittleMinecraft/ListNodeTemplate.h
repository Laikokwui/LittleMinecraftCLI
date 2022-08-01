#pragma once

template <class T>
class ListNode {
public:
    T fData; // data
	ListNode* fNext; // next node

	// Default constructor
	ListNode() {
		fNext = nullptr;
	}

	// Constructor with one parameter
	ListNode(T aData) {
		fData = aData;
		fNext = nullptr;
	}

	// Destructor
	~ListNode() {}
};
