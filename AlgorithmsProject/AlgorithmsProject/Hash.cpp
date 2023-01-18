#include"hashTable.h"


class Hash
{
private:
    const int NumberOfBuckets = 6037;
    NodeEntry** hashTable;

public:

    Hash()
    {

        hashTable = new NodeEntry * [NumberOfBuckets];
        for (int i = 0; i < NumberOfBuckets; i++)
        {
            hashTable[i] = NULL;
        }
    }

    int HashFunction(int key)
    {
        return key % NumberOfBuckets;
    }

    void Insert(int key, int index)
    {
        int insertionPoint = HashFunction(key);
        NodeEntry* entry = new NodeEntry(insertionPoint, index);

        if (hashTable[insertionPoint] == NULL) 
        {
            hashTable[insertionPoint] = entry;
        }
        else 
        {
            NodeEntry* runner = hashTable[insertionPoint];
            while (runner->next != NULL) 
            {
                runner = runner->next;
            }
            runner->next = entry;
        }

    }

    int Search(int key)
    {
        int searchPoint = HashFunction(key);
        NodeEntry* searchNode;
        searchNode = hashTable[searchPoint];

        while (searchNode != NULL)
        {
            if (searchNode->key == searchPoint)
            {
                return searchNode->arrayIndex;
            }
            else
                searchNode->next;
        }

        return -1;

    }

    void outputHash()
    {
        for (int k = 0; k < 7000; k++)
        {
            std::cout << k;
            if (hashTable[k]->arrayIndex != NULL)
            {
                NodeEntry* tmp;
                tmp = hashTable[k];
                do {
                    std::cout << " --> " << tmp->key << " --> " << tmp->arrayIndex;
                    tmp = tmp->next;
                } while (tmp != NULL);
                
            }
            std::cout << std::endl;
        }
    }
};