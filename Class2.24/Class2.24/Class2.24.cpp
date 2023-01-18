// Class2.24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define ARRAY_SIZE 3
typedef string Names[ARRAY_SIZE];
typedef int IDs[ARRAY_SIZE];

void printArray(string names[], int ids[], int size);

void getInputFromFile(string n[], int i[], const int size);

int main(void)
{
    Names names;
    IDs ids;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << "Name and ID: ";
        cin >> names[i] >> ids[i];
    }
    return 0;
}

void printArray(string names[], int ids[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Name: " << names[i] << " ID: " << ids[i];
    }
}

void getInputFromFile(string n[], int i[], const int size) {
    ifstream inFile;
    inFile.open("Data.txt");
    if (inFile.fail()) {
        cout << "Couldn't open file\n";
        return;
    }

    string name = "";
    int id = -1;
    int k = 0;
    while (inFile >> name && k < size) {
        inFile >> id;
        n[k] = name;
        i[k] = id;
        k++;
    }
    if (!inFile.eof() && k == size) {
        cout << "Some file contents may not have been read. \n"
    }
    inFile.close();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
