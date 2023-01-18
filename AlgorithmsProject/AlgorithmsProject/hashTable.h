#pragma once
#include <fstream> 
#include <iostream>



class NodeEntry
{
public:
    int arrayIndex, key;
    NodeEntry* next;
    NodeEntry(int k, int v)
    {
        key = k;
        arrayIndex = v;
        next = NULL;
    }
};
