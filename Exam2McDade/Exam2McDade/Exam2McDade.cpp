// Exam2McDade.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Test.h"

void printList(Test t[], const int size); //prints the entire array, each item on a line
float sumOfList(Test t[], const int size); // returns sum all items in the array
void initList(Test t[], const int size); //initializes each array element randomly in range 0..10
								//use the specific constructor when initializing


int main(void)
{
	Tdata tdata;
	srand(time_t());

	initList(tdata, SIZE);
	printList(tdata, SIZE);
	std::cout << "Sum " << sumOfList(tdata, SIZE) << std::endl;


	return 0;
}

void printList(struct Test t[], const int size) {
	for (int i = 0; i < size; i++) {
		std::cout << t[i].f << std::endl;
	}
}
float sumOfList(struct Test t[], const int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += t[i].f;
	}

	return sum;
}
void initList(struct Test t[], const int size) {
	for (int i = 0; i < size; i++) {
		t[i].f = rand()%10;
	}
}