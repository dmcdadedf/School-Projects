// CS111Project1-McDade.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

#define MAX_SIZE 20
typedef string BoatNames[MAX_SIZE];
typedef string BoatOwnerNames[MAX_SIZE];
typedef double BoatSizes[MAX_SIZE];

//preconditions: --
//postconditions: all array elements are intialized as follows:
//              string: ""
//              int: -1
void initArrays(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int size);

//preconditions: --
//postconditions: writes content of arrays bounded by size in the following order: boatname, 
//                ownerName, size
void printBoatData(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int size);

//preconditions:  all arrays have been initialized
//postconditions: arrays are filled with data from data.tx. 
//                File format is: owner name, boat size, boat name
 //               The parameter size is the number of lines in the file
//Notes: assumes a single string for owner name or boat name. Woods 320 Privacy is valid,
//       Tiger Woods 320 Privacy is not valid (line has three strings)
//       all file operations--opening, checking, reading, closing--must occur in readData(...)
//       It is possible that size may be one more than the number of data lines depending on
//       how the EOF character is represented.
void readData(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int& size);

//preconditions:  all arrays have valid data
//postconditions: prints data associated with target (boat owner); 
//                if not found, print Owner target not found
void findDataByOwnerName(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int size, string target);

int main(void)
    {
        BoatNames boatNames;
        BoatOwnerNames boatOwnerNames;
        BoatSizes boatSizes;
        
        int arraySize = MAX_SIZE;

        initArrays(boatOwnerNames, boatNames, boatSizes, MAX_SIZE);
        readData(boatOwnerNames, boatNames, boatSizes, arraySize);
        cout << "Number of lines read " << arraySize << endl;
        string target;
        cout << "Enter name of owner ";
        cin >> target;
        findDataByOwnerName(boatOwnerNames, boatNames, boatSizes, arraySize, target);
        cout << endl;
        printBoatData(boatOwnerNames, boatNames, boatSizes, arraySize);

        return 0;

    }

void initArrays(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int size) {
    for (int j = 0; j < MAX_SIZE; j++) {
        ownerNames[j] = "";
        boatNames[j] = "";
        sizes[j] = -1;
    }
}

void readData(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int& size) {
    ifstream inFile;
    inFile.open("data.txt");
    if (inFile.fail()) {
        cout << "Couldn't open data file\n";
        return;
    }

    string owner = "";
    double boatSize = -1.0;
    string boat = "";
    int actualFileSize = 0;

    while (inFile >> owner && actualFileSize < size) {
        
        ownerNames[actualFileSize] = owner;
        inFile >> boatSize;
        sizes[actualFileSize] = boatSize;
        inFile >> boat;
        boatNames[actualFileSize] = boat;
        actualFileSize++;
    }

    if (!inFile.eof() && actualFileSize == size) {

        cout << "Some file contents may not have been read. \n";

    }

    size = actualFileSize;

    inFile.close();
}

void findDataByOwnerName(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int size, string target) {
    bool found = false;
    for (int j = 0; j < size; j++) {
        if (ownerNames[j] == target) {
            cout  << "Boat " << ownerNames[j] << " owned by " << boatNames[j] << " size " << sizes[j] << endl;
            found = true;
        }
    }
    if (found == false) {
        cout << "Owner target not found";
    }

}

void printBoatData(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int size) {
    cout << "\n";
    for (int j = 0; j < size; j++) {
            cout  << "Boat " << ownerNames[j] << " owned by " << boatNames[j] << " size " << sizes[j] << endl;
    }
}

