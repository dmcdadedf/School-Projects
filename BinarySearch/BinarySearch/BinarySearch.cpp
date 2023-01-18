// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#define SIZE 30000
#define NOT_FOUND -1

typedef int Data[SIZE];

void initializeRandom(int d[], const int size);
void initializeInOrder(int d[], const int size);

int linearSearch(int d[], int target, const int size);
long int numberOfComparisons;

int binarySearch(int d[], int target, const int size);


int main(void)
{
    numberOfComparisons = 0;
    int effectiveArraySize = 10;
    Data data;
    srand(0); // seeds the rand number generator. NEVER call more than once
    initializeInOrder(data, SIZE);



    //for (int j = 10; j < SIZE; j += 10) {            // experimental loop
    //    int target = rand() % effectiveArraySize;
    //    int result = linearSearch(data, target, effectiveArraySize);
    //    cout <<"Array Size " << effectiveArraySize <<  " Result " << result << " comparisons " << numberOfComparisons << endl;
    //    effectiveArraySize += 10;
    //    numberOfComparisons = 0;
    //}

    for (int j = 10; j <= SIZE; j += 10) {            // experimental loop
       int target = rand() % effectiveArraySize;
       numberOfComparisons = 0;
       int result = linearSearch(data, target, effectiveArraySize);
       cout <<"\nLinear Array Size " << effectiveArraySize <<  " Result " << result << " comparisons " << numberOfComparisons << endl;
       numberOfComparisons = 0; 
       result = binarySearch(data, target, effectiveArraySize);
       cout << "Binary Array Size " << effectiveArraySize << " Result " << result << " comparisons " << numberOfComparisons << endl;
       effectiveArraySize += 10;
       numberOfComparisons = 0;
    }

    return 0;
}

void initializeInOrder(int d[], const int size) {
    for (int i = 0; i < size; d[i] = i, i++);
}

void initializeRandom(int d[], const int size) {
    for (int i = 0; i < size; d[i] = i, i++) {
        d[i] = rand() % size;                          // gives rand size within size of array
    }
}

int linearSearch(int d[], int target, const int size) {
    for (int i = 0; i < size; i++) {
        numberOfComparisons++;
        if (d[i] == target)
            return i;
    }
    return NOT_FOUND;
}

int binarySearch(int d[], int target, const int size) {
    int left = 0;
    int right = size - 1;
    while (right >= left) {
        int middle = (left + right) / 2;
        numberOfComparisons++;
        if (d[middle] == target)
            return middle;
        numberOfComparisons++;
        if (target < d[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }
    cout << "Target Not Found";
    return NOT_FOUND;
}