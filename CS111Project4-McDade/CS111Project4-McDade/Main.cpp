// CS111Project4-McDade.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "BoatStruct.h"


//preconditions: --
//postconditions: writes content of array bounded by size in the following order: boatname, 
//                ownerName, size
void printBoatData(struct BoatStruct a[], int size);

//preconditions:  array of structs has been initialized
//postconditions: array of structs is filled with data from data.tx. 
//                File format is: owner name, boat size, boat name
 //               The parameter size is the number of lines in the file
//Notes: assumes a single string for owner name or boat name. Woods 320 Privacy is valid,
//       Tiger Woods 320 Privacy is not valid (line has three strings)
//       all file operations--opening, checking, reading, closing--must occur in readData(...)
//       It is possible that size may be one more than the number of data lines depending on
//       how the EOF character is represented.
void readData(struct BoatStruct a[], int& size);

//preconditions:  array of structs has valid data
//postconditions: prints data associated with target (boat owner); 
//                if not found, print Owner target not found
void findDataByOwnerName(struct BoatStruct a[], int size, std::string target);



int main(void)
{
    int arraySize(MAX);
    BoatStruct boatData[MAX];
    readData(boatData, arraySize);
    std::cout << "Number of lines read " << arraySize << std::endl;
    std::string target;15
    std::cout << "Enter name of owner ";
    std::cin >> target;
    findDataByOwnerName(boatData, arraySize, target);
    std::cout << std::endl;
    printBoatData(boatData, arraySize);

    return 0;
}

void readData(struct BoatStruct a[],int& size) {
    std::ifstream inFile;
    inFile.open("data.txt");
    if (inFile.fail()) {
        std::cout << "Couldn't open data file\n";
        size = 0;
        return;
    }

    std::string owner = "";
    double boatSize = -1.0;
    std::string boat = "";
    int actualFileSize = 0;

    while (inFile >> owner && actualFileSize < size) {

        a[actualFileSize].boatOwnerName = owner;
        inFile >> boatSize;
        a[actualFileSize].boatSize = boatSize;
        inFile >> boat;
        a[actualFileSize].boatName = boat;
        actualFileSize++;
    }

    if (!inFile.eof() && actualFileSize == size) {

        std::cout << "Some file contents may not have been read. \n";

    }

    size = actualFileSize;

    inFile.close();
}

void findDataByOwnerName(struct BoatStruct a[],int size, std::string target) {
    bool found = false;
    for (int j = 0; j < size; j++) {
        if (a[j].boatOwnerName == target) {
            a[j].print();
            found = true;
        }
    }
    if (found == false) {
        std::cout << "Owner target not found";
    }

}

void printBoatData(struct BoatStruct a[],int size) {
    std::cout << "\n";
    for (int j = 0; j < size; j++) {
        a[j].print();
    }
}

