
// Class2.22.21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define ARRAY_SIZE 500

int sumArray(int n[], int size);

void printArray(int n[], int size);

int main()
{

    int a[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        a[i] = i;
        //cout << a[i] << " ";
    }
    int arraySum = 0;
    //for (int i = 0; i < ARRAY_SIZE; i++) {
    //    arraySum += a[i];
    //    //cout << a[i] << " ";
    //}
    return 0;
}

void printArray(int n[], int size) {
    for (int i = 0; i < size; i++) {
        cout << " " << n[i];
    }
}

int sumArray(int n[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += n[i];
        //cout << a[i] << " ";
    }
    return sum;
}

