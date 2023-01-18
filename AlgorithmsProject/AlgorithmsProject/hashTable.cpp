#include"hashTable.h"
#include<cstdlib>
#include<cstdio>

class Hash
{
    private:
        const int NumberOfBuckets = 7000;
        NodeEntry** hashTable;

    public:
       
        Hash()
        {

            hashTable = new NodeEntry* [NumberOfBuckets];
            for (int i = 0; i < NumberOfBuckets; i++) 
            {
                hashTable[i]= NULL;
            }
        }

        int HashFunction(int key) 
        {
            return key % NumberOfBuckets;
        }

        void Insert(int key, int index)
        {
            int insertionPoint = HashFunction(key);
            NodeEntry* entry = new NodeEntry(key, index);



           /* while (entry != NULL) 
            {
                previous = entry;
                entry = entry->next;
            }

            if (entry == NULL) 
            {
                entry = new NodeEntry(key, index);
                if (previous == NULL)
                    hashTable[insertionPoint] = entry;
                else
                    previous->next = entry;
            }
            else 
            {
                entry->arrayIndex = index;
            }*/

        }
        
        int Search(int key) 
        {
            int searchPoint = HashFunction(key);
            NodeEntry* entry = hashTable[searchPoint];
            while (entry != NULL)
            {
                if (entry->key == key)
                {
                    return entry->arrayIndex;
                }
                else
                    entry->next;
            }

            return -1;
            
        }

        
};

