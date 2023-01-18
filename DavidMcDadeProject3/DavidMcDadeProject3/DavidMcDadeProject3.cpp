// DavidMcDadeProject3.cpp
// Authors: David McDade	Partner: Patrick McDonagh
//
// Date: November 22, 2021
//
//Program: This program takes input from a file containing student names and student numbers. It inserts this into a hashtable using the student number as the key. 
//It then repeatedly prompts the user if they want to search for a student using a 5 digit student number, print the entire list of students and numbers, or end the program.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int hashSize = 61;   // 61 chosen because it is the next prime after 2 times the number of data entries.

struct nodeType
{
    string studentName;
    int studentNum;
    nodeType* nextPtr;
};

typedef nodeType* nodePtrType;
typedef nodePtrType hashTableType[hashSize];

/* Given:  an empty hash table
   Task:   To initialize each bucket on the hashtable to an array
   Return: An initialized hashtable
*/
void initializeTable(hashTableType hashTable);

/* Given:  hashTable - the current hash table
           number - the student number read in from the file
           name - the student name read in from the file
   Task:   To insert number into the pointer's studentNum and to insert name into the pointer's student name
   Return: A hashtable with the new data entered
*/
void insertTable(hashTableType hashTable, int number, string name);

/* Given:  hashTable - the current hash table
           number - the student number read in from the file
           name - the student name read in from the file
   Task:   To prompt the user To enter a 0, 1, or 5 digit student number. If they enter a 0 the program ends, if they enter a 1, the entire list of students and numbers is printed, 
   if they enter a student number, the hashtable is searched for the name of the student with that ID, if no student is found it will print no student found.
   Return: An output of the student number and whom it belongs to, if the number is not found, student not found, the whole list of students, or end the program.
*/
void findTable(hashTableType hashTable, int number);

/* Given:  hashTable - the current hash table
   Task:   To empty all of the data in the hashtable.
   Return: an empty hashtable.
*/
void emptyTable(hashTableType hashTable);

/* Given:  hashTable - the current hash table
   Task:   Prints all of the items stored in the hashtable in ascending bucket order, printing out bucket 0 first all the way through the last bucket.
   Return: nothing
*/
void dumpTable(hashTableType hashTable);


int main()
{
    hashTableType hashTable;
    fstream file;
    string studentName;
    int studentNumber;
    string firstName;
    string lastName;

    initializeTable(hashTable);

    file.open("students.txt", ios::in);

    if (file.fail())
    {
        cerr << "Could not open file students.txt for reading" << endl;
        exit(1);
    }

    for (int k = 0; k < 30; k++) {              //stores the data from the file into the hashtable
        file >> firstName;
        file >> lastName;
        file >> studentNumber;
        
        studentName = firstName + " " + lastName;

        insertTable(hashTable, studentNumber, studentName);
    }

    file.close();

    studentNumber = -1;     //making sure the loop runs at least once by setting studentNumber to 0

    while (true) {          // will run until a 0 is entered
        cout << "Please enter in the 5 digit Student Number, 1 to see all students, or 0 to end : ";
        cin >> studentNumber;           
        cout << endl;
        if (studentNumber == 0)
            return 0;           // if 0 is entered end the program
        else if (studentNumber == 1) 
            dumpTable(hashTable);       // if 1 is entered, print out all items in hashtable
        else
            findTable(hashTable, studentNumber);    // find the student name that matches with the student number
    }
}

void initializeTable(hashTableType hashTable)
{
    for (int k = 0; k < hashSize; k++)
        hashTable[k] = NULL;
}

void insertTable(hashTableType hashTable, int number, string name)
{
    string junk;
    nodePtrType nextPtr, nodePtr;

    int location = 0;
    location = number % hashSize;
    

    if (hashTable[location] == NULL)
    {
        try
        {
            nodePtr = new nodeType;
        }
        catch (bad_alloc)
        {
            cerr << "Memory allocation error! Exiting the program.\n" << endl;
            cerr << "Press Enter" << endl;
            emptyTable(hashTable);
            getline(cin, junk, '\n');
            exit(1);
        }

        
        nodePtr-> studentNum = number;  // if it is the list is empty, this enters the data to a new first pointer
        nodePtr-> studentName = name;
        nodePtr->nextPtr = NULL;
        hashTable[location] = nodePtr;
    }
    else   // if there is something already in the list
    {
        nextPtr = hashTable[location];
        try
        {
            nodePtr = new nodeType;
        }
        catch (bad_alloc)
        {
            cerr << "Memory allocation error! Exiting the program.\n" << endl;
            cerr << "Press Enter" << endl;
            emptyTable(hashTable);
            getline(cin, junk, '\n');
            exit(1);
        }

        nodePtr->studentNum = number;       // insert the item at the front of the list
        nodePtr->studentName = name;
        nodePtr->nextPtr = hashTable[location];
        hashTable[location] = nodePtr;

    }
}

void findTable(hashTableType hashTable, int number)
{
    nodePtrType currentPtr;
    string studentName;
    int location = 0;
    location = number%hashSize;

    currentPtr = hashTable[location];

    

    while (currentPtr != NULL)
    {
        if (currentPtr->studentNum == number) {
            studentName = currentPtr->studentName;
            cout << "Student Number: " << number << " belongs to " << studentName << endl << endl;
            return;
        }
        else
            currentPtr = currentPtr->nextPtr;
    }
    
    if (currentPtr == NULL)
        cout << "Student Not Found " << endl << endl;
}

void emptyTable(hashTableType hashTable)
{
    nodePtrType currentPtr, savedPtr;

    for (int k = 0; k < hashSize; k++)
    {
        currentPtr = hashTable[k];
        while (currentPtr != NULL)
        {
            savedPtr = currentPtr->nextPtr;
            delete currentPtr;
            currentPtr = savedPtr;
        }
    }

    cout << "The hash table has been emptied" << endl;
}


void dumpTable(hashTableType hashTable)
{
        int location;
        nodePtrType currentPtr;

        for (location = 0; location < hashSize; location++)
        {
            currentPtr = hashTable[location];

            while (currentPtr != NULL)
            {
                cout << currentPtr->studentName << " : " << currentPtr->studentNum << endl << endl;
                currentPtr = currentPtr->nextPtr;
            }
        }
    

    cout << "*** End of table contents ***" << endl;
}
