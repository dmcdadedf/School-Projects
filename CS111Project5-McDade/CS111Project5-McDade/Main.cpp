// CS111Project4-McDade.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "BoatStruct.h"


//preconditions: --
//postconditions: writes content of linked list bounded by size in the following order: boatname, 
//                ownerName, size
void printBoatData(BoatStructPtr& head);

//preconditions:  linked list has been initialized
//postconditions: linked list is filled with data from data.tx. 
//                File format is: owner name, boat size, boat name
 //               The parameter size is the number of lines in the file
//Notes: assumes a single string for owner name or boat name. Woods 320 Privacy is valid,
//       Tiger Woods 320 Privacy is not valid (line has three strings)
//       all file operations--opening, checking, reading, closing--must occur in readData(...)
//       It is possible that size may be one more than the number of data lines depending on
//       how the EOF character is represented.
void readData(BoatStructPtr& head);

//preconditions:  linked list has valid data
//postconditions: prints data associated with target (boat owner); 
//                if not found, print Owner target not found
BoatStructPtr findDataByOwnerName(BoatStructPtr& head, std::string target);

//preconditions:  linked list has valid data
//postconditions: prints data associated with target (boat owner); 
//                if not found, print Owner target not found
void headInsert(BoatStructPtr& head, BoatStructPtr& newItem);

//preconditions:  linked list has valid data
//postconditions: prints data associated with target (boat owner); 
//                if not found, print Owner target not found
void deleteList(BoatStructPtr& head); //delete all elements on the list; h points to NULL


int main(void)
{
    BoatStructPtr head = NULL;
    deleteList(head);
  
    readData(head);
    std::string target;
    printBoatData(head);
    std::cout << "Enter name of owner ";
    std::cin >> target;
    BoatStructPtr search = findDataByOwnerName(head,target);
   if (search == head && target != head->boatOwnerName) {
        return -1;
    }
    std::cout << std::endl;
    search->print();
    deleteList(head);

    return 0;
}

void readData(BoatStructPtr& head) {
    std::ifstream inFile;
    inFile.open("data.txt");
    if (inFile.fail()) {
        std::cout << "Couldn't open data file\n";
        return;
    }

    std::string owner = "";
    double boatSize = -1.0;
    std::string boat = "";
    

    while (!inFile.eof()) {
        inFile >> owner;
        inFile >> boatSize;
        inFile >> boat;

        BoatStructPtr t = new BoatStruct(owner,boat,boatSize);

        headInsert(head,t);
    }

    inFile.close();
}

BoatStructPtr findDataByOwnerName(BoatStructPtr& head, std::string target){
    BoatStructPtr itr = head;
    while (itr)
    {
        if (itr->boatOwnerName == target) {
            return itr;
        }
        itr = itr->next;
    }
    if (itr == NULL) {
        std::cout << "\n";
        std::cout << "Target Not Found";
        return head;
    }
    

}

void printBoatData(BoatStructPtr& head) {
    std::cout << "\n";
    BoatStructPtr f = head;
    for (; f; f = f->next)
    {
        std::cout << "Boat " << f->boatName << " owned by " << f->boatOwnerName << " size " << f->boatSize << std::endl;
    }
    
}
    


void headInsert(BoatStructPtr& h, BoatStructPtr& newItem) {
    newItem->next = h;
    h = newItem;
    newItem = NULL;
}

void deleteList(BoatStructPtr& head) {
    if (head == NULL) {
        return;
    }
    for (; head != NULL; ) {
        BoatStructPtr t = head;              // Temp pointer to head of list
        head = head->next;          // removes the item from the list
        t->next = NULL;
        delete t;

    }
}

