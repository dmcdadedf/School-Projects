#pragma once

using namespace std;

const int prime = 6007;
// Try 101 for a larger hash table.

struct nodeType
{
    int structIndex;
    int key;
    nodeType* nextPtr;
};

typedef nodeType* nodePtrType;
typedef nodePtrType hashTableType[prime];
//
//int hashFn(int key);
//
//void initializeTable(hashTableType hashTable);
//
//void insertTable(hashTableType hashTable, int key);
//
//void emptyTable(hashTableType hashTable);
//
//int findTable(hashTableType hashTable, int key);
//
//void dumpTable(hashTableType hashTable);

