#pragma once


struct dataStruct {
	//member variables
	int key;
	int associate;
};



// preconditions: -
// postconditions: the array is initiatied to int 0 and the first index of the array is set to the array size
void initArray(dataStruct* numArray, int size);


// preconditions - all arrays have been initialized
// postconditions - writes file information into the array starting at index 1
void readData(dataStruct* numArray);


//preconditions - the array is filed with information and not empty
//postconditions - prints the information from the array 10 items per line
void printData(dataStruct* numArray);

//preconditions - 
//postconditions - returns the number of items in the file
int getFileSize();

/* Given:  A     An array of integers
		   d     The maximum number of digits in each integer in A.
   Task:   To sort the integers in A into ascending order by using radix sort (with CountingSort as its helping routine).
   Return: A     The array of integers, now in ascending order.
*/
void RadixSort(dataStruct* numArray, int d);

/*
* Given:   A   Array to be sorted. It must contain integers with a small number of digits, such as the 2-digit numbers shown above.
* Task:    To sort array A into ascending order according to the digit indicated by parameter CurrentDigit.
* Return:  B   Containing the data from A, sorted into ascending order by the CurrentDigit.
*/
void CountingSort(dataStruct* numArray, dataStruct* B, int CurrentDigit);

void prompt(dataStruct* numArray);



