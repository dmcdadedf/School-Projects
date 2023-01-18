#pragma once
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "SinglyLinkedList.h"

class Stack {
private:
    LinkedList linkedList;
    int size;

public:
    Stack() {
        size = 0;
    }

    void Push(int newData) {
        // Create a new node and prepend
        Node* newNode = new Node(newData);
        linkedList.Prepend(newNode);
        size += 1;
    }

    int Pop() {
        // Copy list head's data
        int poppedItem = linkedList.GetHeadData();

        // Remove list head
        linkedList.RemoveAfter(nullptr);
        
        size -= 1;
        // Return popped item
        return poppedItem;
        
    }

    void Print(std::ostream& printStream) {
        linkedList.PrintList(printStream);
    }
    int getSize() {
        return size;
    }
};

#endif