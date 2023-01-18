// Exam1McDade.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#define ARRAY_SIZE 12

//Precondition: a is an initialized array, size is array size
//Postcondition: a is initialized with ints in the range of [0...10000]
void initArray(int a[], const int size);

//Precondition: a is an initialized array, size is array size
//Postcondition: a is sorted using Selection Sort in ascending order
void sortArray(int a[], const int size);

//Precondition: --
//Postcondition: array contents printed to the screen(cout)
void printArray(const int a[], const int size);

//Precondition: a has values, size is array size
//Postcondition: array average is returned
int averageArray(const int a[], const int size);
//Precondition: a has values, index is within the array
//Postconditon: the values are swapped
void swap(int a[], int index1, int index2);

int main(void)
{
	srand(0);
	int numbers[ARRAY_SIZE];
	initArray(numbers, ARRAY_SIZE);
	printArray(numbers, ARRAY_SIZE);
	sortArray(numbers, ARRAY_SIZE);
	printArray(numbers, ARRAY_SIZE);
	cout << "Average " << averageArray(numbers, ARRAY_SIZE);
	return 0;
}

void initArray(int a[], const int size) {
	for (int n = 0; n < size; n++) {
		a[n] = rand();
	}
}

void sortArray(int a[], const int size) {
	int min = INT_MAX;
	for (int f = 0; f < size; f++) {
		for (int n = f; n < size; n++) {
			if (min > a[n]) {
				min = n;
			}
		}
		swap(a, f, min);
	}
}

void printArray(const int a[], const int size) {
	for (int n = 0; n < size; n++) {
		cout << a[n] << " ";
	}
	cout << "\n";
}

int averageArray(const int a[], const int size) {
	int sum = 0;
	for (int n = 0; n < size; n++) {
		sum += a[n];
	}
	return sum/size;
}

void swap(int a[], int index1, int index2) {
	int temp = -1;
	temp = a[index1];
	a[index1] = a[index2];
	a[index2] = temp;
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
