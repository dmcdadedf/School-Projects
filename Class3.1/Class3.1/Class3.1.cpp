//

//  main.cpp

//  CS111_W3_C2_||_Arrays

//

//  Created by Birmingham, William on 2/24/21.

//



#include <iostream>

#include <string>

#include <fstream>



using namespace std;

#define ARRAY_SIZE 1

typedef string Names[ARRAY_SIZE];

typedef int IDs[ARRAY_SIZE];

//Precondition: legals values in names and ids, size >= 0
//Postcondition: arrays are written to screen

void printArray(const string names[], const int ids[], const int size);

//Precondition: arrays contain no value (aside from initialization), size >= 0
//Postcondition: arrays contain user-supplied information from KEYBOARD

void getInputFromKeyboard(string n[], int i[], const int size);

//Precondition: arrays contain no value (aside from initialization), size >= 0
//              actualFileSize must be zero
//Postcondition: arrays contain user-supplied information from FILE
//              actualFileSize is the number of lines read

void getInputFromFile(string n[], int i[], const int size, int& actualFileSize);

// ------------- search Function
// Preconditions: n[] and i[] are populated

int searchForIndexBasedOnName(const string n[], const int i[], const int size, const string target);

int searchForIndexBasedOnID(const string n[], const int i[], const int size, const string target)


int main(void) {

    Names names;   //string names[ARRAY_SIZE];

    IDs ids;       //int ids[ARRAY_SIZE];



//    getInputFromKeyboard(names, ids, ARRAY_SIZE);

//    for (int i = 0; i < ARRAY_SIZE; i++){

//        cout << "Name and ID: ";

//        cin >> names[i] >> ids[i];

//    }

    int actualLinesRead = 0;

    getInputFromFile(names, ids, ARRAY_SIZE, actualLinesRead);

    printArray(names, ids, actualLinesRead);// ARRAY_SIZE);

    string t = "";
    cout << "input a search Target: ";
    cin >> t;
    int index = searchForIndexBasedOnName(names, ids, actualLinesRead, t);
    if (index == -1) {
        cout << "Name not in array \n";
    }
    else {
        cout << "Index "< index << "\n"
    }
    cout << "Index " << index;


    return 0;

}



void printArray(const string names[], const int ids[], const int size) {

    if (!size) {

        cout << "File was empty\n";

    }

    for (int i = 0; i < size; i++) {

        cout << "Name: " << names[i] << " ID: " << ids[i] << endl;

    }

}

void getInputFromKeyboard(string n[], int i[], const int size) {

    for (int j = 0; j < ARRAY_SIZE; j++) {

        cout << "Name and ID: ";

        cin >> n[j] >> i[j];

    }

}

void getInputFromFile(string n[], int i[], const int size, int& actualFileSize) {

    ifstream inFile;

    inFile.open("Long.txt");

    if (inFile.fail()) {

        cout << "Couldn't open data file\n";

        return;

    }

    string name = "";

    int id = -1;

    //    int k = 0;

    while (inFile >> name && actualFileSize < size) {

        inFile >> id;

        n[actualFileSize] = name;

        i[actualFileSize] = id;

        actualFileSize++;

    }

    if (!inFile.eof() && actualFileSize == size) {

        cout << "Some file contents may not have been read. \n";

    }

    inFile.close();

}

int searchForIndexBasedOnName(const string n[], const int i[],const int size, const string target ) {
    if (int j = 0; j < size; j++) {
        if (n[j] == target) {
            cout << "Target Found \n";
            return j;
        }
        return -1;
    }
}

int searchForIndexBasedOnID(const string n[], const int i[], const int size, const int target) {
    if (int j = 0; j < size; j++) {
        if (i[j] == target) {
            cout << "Target Found \n";
            return j;
        }
        return -1;
    }
}

