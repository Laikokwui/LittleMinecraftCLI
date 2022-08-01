#pragma once

#include "TreeNodeTemplate.h"
#include "TreeVisitor.h"
#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
class AVLTree {
public:
    TreeNode<T>* fRoot;

    // AVLTree default constructor
    AVLTree() {
        fRoot = NULL;
    }

    // AVLTree destructor
    ~AVLTree() {}

    // AVLTree get max value
    int max(int aHeight, int bHeight) {
        if (aHeight > bHeight) {
            return aHeight;
        }
        else {
            return bHeight;
        }
    }

    // AVLTree find the node with minimum value 
    TreeNode<T>* min(TreeNode<T>* aTreeNode) {
        TreeNode<T>* temp = aTreeNode;
        while (temp->fLeft != NULL) {
            temp = temp->fLeft;
        }
        return temp;
    }

    // AVLTree get tree height
    int height(TreeNode<T>* aTreeNode) {
        if (aTreeNode == NULL) {
            return 0;
        }
        return aTreeNode->fHeight;
    }

    // AVLTree Get Balance factor  
    int balancefactor(TreeNode<T>* aTreeNode) {
        if (aTreeNode == NULL) {
            return 0;
        }
        return height(aTreeNode->fLeft) - height(aTreeNode->fRight);
    }

    // AVLTree allocate new node
    TreeNode<T>* newTreeNode(const T& aData) {
        TreeNode<T>* treenode = new TreeNode<T>();
        treenode->fData = aData;
        treenode->fLeft = NULL;
        treenode->fRight = NULL;
        treenode->fHeight = 1;
        return(treenode);
    }

    // AVLTree right rotation
    TreeNode<T>* rotateRight(TreeNode<T>* aTreeNode) {
        TreeNode<T>* treenode = aTreeNode->fLeft;
        TreeNode<T>* childnode = treenode->fRight;
        // Perform rotation  
        treenode->fRight = aTreeNode;
        aTreeNode->fLeft = childnode;
        // Update heights  
        aTreeNode->fHeight = max(height(aTreeNode->fLeft), height(aTreeNode->fRight)) + 1;
        treenode->fHeight = max(height(treenode->fLeft), height(treenode->fRight)) + 1;
        return treenode; // Return new root  
    }

    // AVLTree left rotation
    TreeNode<T>* rotateLeft(TreeNode<T>* aTreeNode) {
        TreeNode<T>* treenode = aTreeNode->fRight;
        TreeNode<T>* childnode = treenode->fLeft;
        // Perform rotation  
        treenode->fLeft = aTreeNode;
        aTreeNode->fRight = childnode;
        // Update height
        aTreeNode->fHeight = max(height(aTreeNode->fLeft), height(aTreeNode->fRight)) + 1;
        treenode->fHeight = max(height(treenode->fLeft), height(treenode->fRight)) + 1;
        return treenode; // Return new root  
    }

    // AVLTree insertion
    TreeNode<T>* insert(TreeNode<T>* aTreeNode, const T& aData) {
        // normal insertion from the Binary search tree
        if (aTreeNode == NULL) {
            return(newTreeNode(aData));
        }
        if (aData < aTreeNode->fData) {
            aTreeNode->fLeft = insert(aTreeNode->fLeft, aData);
        }
        else if (aData > aTreeNode->fData) {
            aTreeNode->fRight = insert(aTreeNode->fRight, aData);
        }
        else {
            return aTreeNode;
        }
        // update the height of the tree
        aTreeNode->fHeight = 1 + max(height(aTreeNode->fLeft), height(aTreeNode->fRight)); // update height of ancestor node
        int bf = balancefactor(aTreeNode); //get balance factor

        // Left Left case
        if (bf > 1 && aData < aTreeNode->fLeft->fData) {
            return rotateRight(aTreeNode);
        }
        // Right Right case
        if (bf < -1 && aData > aTreeNode->fRight->fData) {
            return rotateLeft(aTreeNode);
        }
        // Left Right Case  
        if (bf > 1 && aData > aTreeNode->fLeft->fData) {
            aTreeNode->fLeft = rotateLeft(aTreeNode->fLeft);
            return rotateRight(aTreeNode);
        }
        // Right Left Case  
        if (bf < -1 && aData < aTreeNode->fRight->fData){
            aTreeNode->fRight = rotateRight(aTreeNode->fRight);
            return rotateLeft(aTreeNode);
        }
        return aTreeNode;
    }

    // AVLTree deletion
    TreeNode<T>* remove(TreeNode<T>* aTreeNode, const T& aData) {
        if (aTreeNode == NULL) {
            return aTreeNode;
        }
        if (aData < aTreeNode->fData) {
            aTreeNode->fLeft = remove(aTreeNode->fLeft, aData);
        }
        else if (aData > aTreeNode->fData) {
            aTreeNode->fRight = remove(aTreeNode->fRight, aData);
        }
        else { 
            if ((aTreeNode->fLeft == NULL) || (aTreeNode->fRight == NULL)) {
                TreeNode<T>* temp = aTreeNode->fLeft ? aTreeNode->fLeft : aTreeNode->fRight;
                if (temp == NULL) {
                    temp = aTreeNode;
                    aTreeNode = NULL;
                }
                else { 
                    *aTreeNode = *temp; 
                }
                delete temp;
            }
            else {
                TreeNode<T>* temp = min(aTreeNode->fRight);
                aTreeNode->fData = temp->fData;
                aTreeNode->fRight = remove(aTreeNode->fRight, temp->fData);
            }
        }

        if (aTreeNode == NULL) {
            return aTreeNode;
        }

        aTreeNode->fHeight = 1 + max(height(aTreeNode->fLeft), height(aTreeNode->fRight)); // update height 
        int bf = balancefactor(aTreeNode); // get balance factor 

        //rotate the tree if unbalanced
        // Left Left Case  
        if (bf > 1 && balancefactor(aTreeNode->fLeft) >= 0) {
            return rotateRight(aTreeNode);
        }
        // Left Right Case  
        if (bf > 1 && balancefactor(aTreeNode->fLeft) < 0) {
            aTreeNode->fLeft = rotateLeft(aTreeNode->fLeft);
            return rotateRight(aTreeNode);
        }
        // Right Right Case  
        if (bf < -1 && balancefactor(aTreeNode->fRight) <= 0) {
            return rotateLeft(aTreeNode);
        }
        // Right Left Case  
        if (bf < -1 && balancefactor(aTreeNode->fRight) > 0) {
            aTreeNode->fRight = rotateRight(aTreeNode->fRight);
            return rotateLeft(aTreeNode);
        }
        return aTreeNode;
    }

    // AVLTree search function but not for class object
    bool search(TreeNode<T>* aTreeNode, const T& aData, bool& found) {
        if (aTreeNode == NULL) {
            found = false;
        }
        else if (aData < aTreeNode->fData) {
            found = search(aTreeNode->fLeft, aData, found);
        }
        else if (aData > aTreeNode->fData) {
            found = search(aTreeNode->fRight, aData, found);
        }
        else {
            found = true;
        }
        return found;
    }

    // AVLTree post order but not for class object
    void postOrder(TreeNode<T>* aTreeNode) {
        if (aTreeNode != NULL) {
            postOrder(aTreeNode->fLeft);
            postOrder(aTreeNode->fRight);
            cout << aTreeNode->fData << " ";
        }
    }

    // AVLTree prints inOrder traversal of the AVL tree
    void inOrder(TreeNode<T>* aTreeNode) {
        if (aTreeNode != NULL) {
            inOrder(aTreeNode->fLeft);
            cout << aTreeNode->fData << " ";
            inOrder(aTreeNode->fRight);
        }
    }

    // AVLTree prints preorder traversal not for class object
    void preOrder(TreeNode<T>* aTreeNode) {
        if (aTreeNode != NULL) {
            cout << aTreeNode->fData << " ";
            preOrder(aTreeNode->fLeft);
            preOrder(aTreeNode->fRight);
        }
    }

    // AVLTree print the postorder object for class object
    void postOrderObject(TreeNode<Item*>* aTreeNode) {
        if (aTreeNode != NULL) {
            postOrderObject(aTreeNode->fLeft);
            postOrderObject(aTreeNode->fRight);
            cout << "<ItemID> (" << aTreeNode->fData->getID() << ") <ItemName> (" << aTreeNode->fData->getName() << ")" << endl;
        }
    }

    // AVLTree print the inorder object for class object
    void inOrderObject(TreeNode<Item*>* aTreeNode) {
        if (aTreeNode != NULL) {
            inOrderObject(aTreeNode->fLeft);
            cout << "<ItemID> (" << aTreeNode->fData->getID() << ") <ItemName> (" << aTreeNode->fData->getName() << ")" << endl;
            inOrderObject(aTreeNode->fRight);
        }
    }
    // AVLTree print the preorder object for class object
    void preOrderObject(TreeNode<Item*>* aTreeNode) {
        if (aTreeNode != NULL) {
            cout << "<ItemID> ("<< aTreeNode->fData->getID() << ") <ItemName> (" << aTreeNode->fData->getName() << ")"<< endl;
            preOrderObject(aTreeNode->fLeft);
            preOrderObject(aTreeNode->fRight);
        }
    }
};
