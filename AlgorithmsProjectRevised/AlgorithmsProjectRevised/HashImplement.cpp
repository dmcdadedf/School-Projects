#include <iostream>
#include <string>
#include "HashHeader.h"

 void emptyTable(hashTableType hashTable);

    /* Given:  item - a string
   Task:   To calculate the hash value of item.
   Return: The hash value for item is returned via the function name.
*/
    int hashFn(int key)
    {
        return key % prime;
    }


    /* Given:  nothing other than hashTable, the empty hash table array
       Task:   To initialize hashTable so that each entry is an empty list
       Return: The properly initialized hashTable.
    */
    void initializeTable(hashTableType hashTable)
    {
        for (int k = 0; k < prime; k++)
            hashTable[k] = NULL;
    }


    /* Given:  hashTable - the current hash table
               str - a string
       Task:   To insert str into hashTable.
       Return: The updated hashTable.
    */
    void insertTable(hashTableType hashTable, int key)
    {
        int location;
        string junk;
        nodePtrType nextPtr, nodePtr;

        location = hashFn(key);

        if (hashTable[location] == NULL)
        {
            try
            {
                nodePtr = new nodeType;
            }
            catch (bad_alloc)
            {
                // Here we give up and exit the program.
                cerr << "Memory allocation error! Exiting the program.\n" << endl;
                cerr << "Press Enter" << endl;
                emptyTable(hashTable);
                getline(cin, junk, '\n');
                exit(1);
            }

            // Insert as the only node on the list:
            nodePtr->key = location;
            nodePtr->structIndex = key;
            nodePtr->nextPtr = NULL;
            hashTable[location] = nodePtr;
        }
        else   // hashTable[location] is not NULL
        {
            nextPtr = hashTable[location];
            try
            {
                nodePtr = new nodeType;
            }
            catch (bad_alloc)
            {
                // Here we give up and exit the program.
                cerr << "Memory allocation error! Exiting the program.\n" << endl;
                cerr << "Press Enter" << endl;
                emptyTable(hashTable);
                getline(cin, junk, '\n');
                exit(1);
            }

            // Insert at front of list:
            nodePtr->key = location;
            nodePtr->structIndex = key;
            nodePtr->nextPtr = hashTable[location];
            hashTable[location] = nodePtr;
        }
    }


    /* Given:  hashTable - the current hash table
       Task:   To clear out all of the data in hashTable so that each hash table location is an empty list.
       Return: The cleared out hashTable.
    */
    void emptyTable(hashTableType hashTable)
    {
        nodePtrType currentPtr, savedPtr;

        for (int k = 0; k < prime; k++)
        {
            currentPtr = hashTable[k];
            // Clear out the list at index k:
            while (currentPtr != NULL)
            {
                savedPtr = currentPtr->nextPtr;
                delete currentPtr;
                currentPtr = savedPtr;
            }
        }

        cout << "The hash table has been emptied" << endl;
    }


    /* Given:  hashTable - the current hash table
               str - a string
       Task:   To discover whether str is present in hashTable and if so, where it is.
       Return: The index where str is found in hashTable or -1 if not found.
    */
    int findTable(hashTableType hashTable, int key)
    {
        int location;
        nodePtrType currentPtr;

        location = hashFn(key);
        currentPtr = hashTable[location];

        if (currentPtr == NULL)
            return -1; -1;   // To indicate that str was not found.

        while (currentPtr != NULL)
        {
            if (currentPtr->structIndex == key)
                return location;  // Here is where str was found.
            else
                currentPtr = currentPtr->nextPtr;
        }

        return -1;   // To indicate that str was not found.
    }


    /* Given:  hashTable - the current hash table
       Task:   Proceeds through the hash table in order, starting with location 0, and displays the list of all items in
               that location of the hash table. Thus the entire hash table's contents are printed.
       Return: nothing
    */
    void dumpTable(hashTableType hashTable)
    {
        int location;
        nodePtrType currentPtr;

        for (location = 0; location < prime; location++)
        {
            cout << "Location " << location;
            currentPtr = hashTable[location];

            if (currentPtr == NULL)
                cout << " is empty." << endl;
            else
            {
                cout << " contains: ";
                while (currentPtr != NULL)
                {
                    cout << "key: " << currentPtr->key << "  indexStruct: " << currentPtr->structIndex;
                    currentPtr = currentPtr->nextPtr;
                }
                cout << endl;
            }
        }

        cout << "*** End of table contents ***" << endl;
    }

    


