#pragma once

template <class T>
class TreeNode {
public:
	T fData;
	TreeNode* fLeft;
	TreeNode* fRight;
	int fHeight;

	// Default constructor
	TreeNode() {
		fLeft = NULL;
		fRight = NULL;
	}

	// Constructor with one parameter
	TreeNode(T aData, int aHeight) {
		fData = aData;
		fLeft = NULL;
		fRight = NULL;
		fHeight = aHeight;
	}

	// Destructor
	~TreeNode() {}
};
