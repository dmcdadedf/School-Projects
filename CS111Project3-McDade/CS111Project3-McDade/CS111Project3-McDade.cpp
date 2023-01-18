// CS111Project3-McDade.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>


using namespace std;
#define SIZE 2000
#define NOT_FOUND -1

typedef int Data[SIZE];


//postcondition: each element is initialized with its index
void initArray(int d[], int size);

int linearSearch(int d[], int target, const int size, int& count);
long int numberOfComparisons;

int binarySearch(int d[], int target, const int size, int& count);

int main(void) {
    srand(time_t(0));
    Data data;
    initArray(data, SIZE);
    int target = 0;
    //declare open, check a data file, called runData in this example
    ofstream runData;
    runData.open("runData.txt");

    if (runData.fail()) {
        cout << "Couldn't open data file\n";
        return 0;
    }

    int workingArraySize = 10;
    for (; workingArraySize < SIZE; workingArraySize += 10) {
        target = rand() % workingArraySize;
        cout << "Target " << target << " " << endl;
        int countLinear = 0;
        int b = linearSearch(data, workingArraySize, target, countLinear);
        int countBinary = 0;
        b = binarySearch(data, workingArraySize, target, countBinary);
        runData << workingArraySize << " " << countLinear << " " << countBinary << endl;
    }
    runData.close();
    return 0;
}

void initArray(int d[], int size) {
    for (int i = 0; i < size; d[i] = i, i++);
    }

    int linearSearch(int d[], int target, const int size, int& count) {
        for (int i = 0; i < size; i++) {
            count++;
            if (d[i] == target)
                return i;
        }
        return NOT_FOUND;
    }

    int binarySearch(int d[], int target, const int size, int& count) {
        int left = 0;
        int right = size - 1;
        while (right >= left) {
            int middle = (left + right) / 2;
            count++;
            if (d[middle] == target)
                return middle;
            count++;
            if (target < d[middle])
                right = middle - 1;
            else
                left = middle + 1;
        }
        return NOT_FOUND;
    }