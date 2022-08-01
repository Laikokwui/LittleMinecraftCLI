/*#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
    fHead = NULL;
}

DoublyLinkedList::DoublyLinkedList(ListNode* aNode) {
    fHead = aNode;
}

// 1. CHeck if node exists using key value
ListNode* DoublyLinkedList::NodeExists(string aKey) {
    ListNode* temp = NULL;
    ListNode* ptr = fHead;

    while (ptr != NULL) {
        if (ptr->fKey == aKey) {
            temp = ptr;
        }
        ptr = ptr->fNext;
    }

    return temp;
}

// 2. Append a node to the list
void DoublyLinkedList::AppendNode(ListNode* aNode) {
    if (NodeExists(aNode->fKey) != NULL) {
        cout << "Node Already exists with key value : " << aNode->fKey << ". Append another node with different Key value" << endl;
    }
    else {
        if (fHead == NULL) {
            fHead = aNode;
            cout << "Node Appended as Head Node" << endl;
        }
        else {
            ListNode* ptr = fHead;
            while (ptr->fNext != NULL) {
                ptr = ptr->fNext;
            }
            ptr->fNext = aNode;
            aNode->fPrev = ptr;
            cout << "Node Appended" << endl;
        }
    }
}

// 3. Prepend Node - Attach a node at the start
void DoublyLinkedList::PrependNode(ListNode* aNode) {
    if (NodeExists(aNode->fKey) != NULL) {
        cout << "Node Already exists with key value : " << aNode->fKey << ". Append another node with different Key value" << endl;
    }
    else {
        if (fHead == NULL) {
            fHead = aNode;
            cout << "Node Prepended as Head Node" << endl;
        }
        else {
            fHead->fPrev = aNode;
            aNode->fNext = fHead;
            fHead = aNode;
            cout << "Node Prepended" << endl;
        }
    }
}

// 4. Insert a Node after a particular node in the list
void DoublyLinkedList::InsertNodeAfter(string aKey, ListNode* aNode) {
    ListNode* ptr = NodeExists(aKey);
    if (ptr == NULL) {
        cout << "No node exists with key value: " << aKey << endl;
    }
    else {
        if (NodeExists(aNode->fKey) != NULL) {
            cout << "Node Already exists with key value : " << aNode->fKey << ". Append another node with different Key value" << endl;
        }
        else {
            ListNode* nextNode = ptr->fNext;
            // inserting at the end
            if (nextNode == NULL) {
                ptr->fNext = aNode;
                aNode->fPrev = ptr;
                cout << "Node Inserted at the END" << endl;
            }

            //inserting in between
            else {
                aNode->fNext = nextNode;
                nextNode->fPrev = aNode;
                aNode->fPrev = ptr;
                ptr->fNext = aNode;

                cout << "Node Inserted in Between" << endl;
            }
        }
    }
}

// 5. Delete node by unique key. Basically De-Link not delete
void DoublyLinkedList::DeleteNodeByKey(string aKey) {
    ListNode* ptr = NodeExists(aKey);
    if (ptr == NULL) {
        cout << "No node exists with key value: " << aKey << endl;
    }
    else {
        if (fHead->fKey == aKey) {
            fHead = fHead->fNext;
            cout << "Node UNLINKED with keys value : " << aKey << endl;
        }
        else {
            ListNode* nextNode = ptr->fNext;
            ListNode* prevNode = ptr->fPrev;
            // deleting at the end
            if (nextNode == NULL) {
                prevNode->fNext = NULL;
                cout << "Node Deleted at the END" << endl;
            }

            //deleting in between
            else {
                prevNode->fNext = nextNode;
                nextNode->fPrev = prevNode;
                cout << "Node Deleted in Between" << endl;
            }
        }
    }
}

// 6th update node
void DoublyLinkedList::UpdateNodeByKey(string aKey, string aData) {

    ListNode* ptr = NodeExists(aKey);
    if (ptr != NULL) {
        ptr->fData = aData;
        cout << "Node Data Updated Successfully" << endl;
    }
    else {
        cout << "Node Doesn't exist with key value : " << aKey << endl;
    }
}

// 7th printing
void DoublyLinkedList::PrintList() {
    if (fHead == NULL) {
        cout << "No Nodes in Doubly Linked List";
    }
    else {
        cout << endl << "Doubly Linked List Values : ";
        ListNode* temp = fHead;

        while (temp != NULL) {
            cout << "(" << temp->fKey << "," << temp->fData << ") <--> ";
            temp = temp->fNext;
        }
    }
}
*/
