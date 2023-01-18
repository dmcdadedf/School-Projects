#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int initialData) {
        data = initialData;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    virtual ~LinkedList() {
        Node* currentNode = head;
        while (currentNode) {
            Node* toBeDeleted = currentNode;
            currentNode = currentNode->next;
            delete toBeDeleted;
        }
    }

    void Append(Node* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void Prepend(Node* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void PrintList(std::ostream& printStream, const std::string& separator = ", ") {
        Node* node = head;
        if (node) {
            // Head node is not preceded by separator
            printStream << node->data;
            node = node->next;
        }
        while (node) {
            printStream << separator << node->data;
            node = node->next;
        }
        printStream << std::endl;
    }

    void InsertAfter(Node* currentNode, Node* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else if (currentNode == tail) {
            tail->next = newNode;
            tail = newNode;
        }
        else {
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }

    void RemoveAfter(Node* currentNode) {
        if (currentNode == nullptr && head) {
            // Special case: remove head
            Node* nodeBeingRemoved = head;
            head = head->next;
            delete nodeBeingRemoved;

            if (head == nullptr) {
                // Last item was removed
                tail = nullptr;
            }
        }
        else if (currentNode->next) {
            Node* nodeBeingRemoved = currentNode->next;
            Node* succeedingNode = currentNode->next->next;
            currentNode->next = succeedingNode;
            delete nodeBeingRemoved;
            if (succeedingNode == nullptr) {
                // Remove tail
                tail = currentNode;
            }
        }
    }

    void InsertionSortSinglyLinked() {
        Node* beforeCurrent = head;
        Node* currentNode = head->next;
        while (currentNode) {
            Node* nextNode = currentNode->next;
            Node* position = FindInsertionPosition(currentNode->data);
            if (position == beforeCurrent) {
                beforeCurrent = currentNode;
            }
            else {
                // Remove, but do not deallocate, currentNode
                Node* succeedingNode = currentNode->next;
                beforeCurrent->next = succeedingNode;
                if (succeedingNode == nullptr) {
                    // Remove tail
                    tail = beforeCurrent;
                }
                currentNode->next = nullptr;

                // Insert currentNode back into list in sorted position
                if (position == nullptr) {
                    Prepend(currentNode);
                }
                else {
                    InsertAfter(position, currentNode);
                }
            }
            currentNode = nextNode;
        }
    }

    Node* FindInsertionPosition(int dataValue) {
        Node* positionA = nullptr;
        Node* positionB = head;
        while (positionB && dataValue > positionB->data) {
            positionA = positionB;
            positionB = positionB->next;
        }
        return positionA;
    }

    // Added for Stack/Queue section
    int GetHeadData() {
        return head->data;
    }
};

#endif