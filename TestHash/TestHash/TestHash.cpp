/* SimpleHashTable.cpp

   Author: Br. David Carlson

   Date: July 21, 2021

   Description:  This is a test program to illustrate the creation and use of a simple hash table. Specifically, it prompts
   the user to enter short strings, such as people's names, placing each in a hash table. At each hash location is a linked
   list, initially empty. Each string that hashes to the same location is inserted at the head of the linked list at that
   location. After data entry is complete (signalled by entering an empty string), the program prompts the user for strings
   to look up. For each string that the user enters, a lookup in the hash table is done for that string. The user is then told
   whether or not the string was found in the hash table. After the last lookup (indicated by entering an empty string), the
   program asks whether the user wants to see all of the data in the hash table. If the reply is Y or y, the program goes
   through the hash table in order, starting with location 0, the list of all items in each location of the hash table is
   printed in the order in which the data is stored. At the end of the program, all of the data for the linked lists is
   removed. That is, the dynamically-allocated memory space is reclaimed.

   Although an object-oriented approach would be better and the use of templates would allow many types of data to be used,
   the goal here was to present a simple, easy-to-read example of a hash table. Thus, these other, more complex, methods of
   implementation were avoided on purpose.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int prime = 23;   // Try 101 for a larger hash table.

struct nodeType
{
    string dataField;
    nodeType* nextPtr;
};

typedef nodeType* nodePtrType;
typedef nodePtrType hashTableType[prime];

int hashFn(string item);

void initializeTable(hashTableType hashTable);

void insertTable(hashTableType hashTable, string str);

void emptyTable(hashTableType hashTable);

int findTable(hashTableType hashTable, string str);

void dumpTable(hashTableType hashTable);


int main()
{
    char replyChar;
    string str;
    string emptyString("");
    int location;
    hashTableType hashTable;

    initializeTable(hashTable);

    cout << "Enter up to " << 3 * prime << " short strings to be placed in the hash table." << endl;
    cout << "Enter the empty string to stop data entry." << endl;
    getline(cin, str);

    while (str != emptyString)
    {
        insertTable(hashTable, str);
        cout << "Enter the next string to be placed in the hash table (or empty string to quit):" << endl;
        getline(cin, str);
    }

    cout << endl << "Now we try lookups." << endl;
    cout << "Enter the string to lookup or an empty string to quit these lookups:" << endl;
    getline(cin, str);

    while (str != emptyString)
    {
        location = findTable(hashTable, str);
        if (location != -1)
            cout << str << " was found at hash table index " << location << endl;
        else
            cout << str << " was NOT found in the hash table" << endl;
        cout << "Enter the string to lookup or an empty string to quit these lookups:" << endl;
        getline(cin, str);
    }

    cout << endl << "Would you like to see the entire contents of the hash table (y/n)?" << endl;
    cin >> replyChar;

    if (tolower(replyChar) == 'y')
        dumpTable(hashTable);

    emptyTable(hashTable);
    return 0;
}


/* Given:  item - a string
   Task:   To calculate the hash value of item.
   Return: The hash value for item is returned via the function name.
*/
int hashFn(string item)
{
    int length, value;

    length = item.length();
    value = 0;

    for (int k = 0; k < length; k++)
    {
        value = (value + 255 * item.at(k)) % prime;
    }

    return value;
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
void insertTable(hashTableType hashTable, string str)
{
    int location;
    string junk;
    nodePtrType nextPtr, nodePtr;

    location = hashFn(str);

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
        nodePtr->dataField = str;
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
        nodePtr->dataField = str;
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
int findTable(hashTableType hashTable, string str)
{
    int location;
    nodePtrType currentPtr;

    location = hashFn(str);
    currentPtr = hashTable[location];

    if (currentPtr == NULL)
        return -1; -1;   // To indicate that str was not found.

    while (currentPtr != NULL)
    {
        if (currentPtr->dataField == str)
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
                cout << currentPtr->dataField << " / ";
                currentPtr = currentPtr->nextPtr;
            }
            cout << endl;
        }
    }

    cout << "*** End of table contents ***" << endl;
}
