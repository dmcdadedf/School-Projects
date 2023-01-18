//  main.cpp
//	CS312 Main Project Part C
//  Created 11/05/2022 by David McDade



#include <iostream> 
#include <fstream> 
#include "Hash.cpp"
#include "hashTable.h"
#include "Main.h"

Hash hashTable;

int main(void) {
	int fileSize = -1;
	
	fileSize = getFileSize();


	dataStruct* numArray = new dataStruct[fileSize];

	//initailize
	initArray(numArray,fileSize);
	
	//read
	readData(numArray);

	//sort
	RadixSort(numArray, 5);

	printData(numArray);

	//insert into Hash Table
	insertDataInHashTable(numArray, hashTable);

	prompt(hashTable, numArray);

	return 0;
}

void initArray (dataStruct* numArray, int size) {

	numArray[0].key = 0;
	numArray[0].associate = size;

	for (int i = 1; i <= size; i++) {
		numArray[i].key = 0;
		numArray[i].associate = 0;
	}
}

int getFileSize() {
	int fileSize = 0;

	std::ifstream inFile;

	inFile.open("keys.txt");
	if (inFile.fail()) {
		std::cout << "Could not open data file\n";
		return -1;
	}

	inFile.seekg(0L, std::ios::end);
	fileSize = 7;
	// Find the number of records and subtract 1 to get high index:
	fileSize = inFile.tellg() / fileSize;

	inFile.close();
	
	return fileSize;
}

void readData(dataStruct* numArray) {

	int i = 0;

	std::ifstream inFile;

	inFile.open("keys.txt");
	if (inFile.fail()) {
		std::cout << "Could not open data file\n";
		return;
	}


	for (int k = 1; k <= numArray[0].associate; k++) {
		inFile >> i;
		if (inFile.eof()) break;
		numArray[k].key = i;
		numArray[k].associate = (i * 10);
	}

	inFile.close();
}

void printData(dataStruct* numArray) {
	std::cout << "Size of array: " << numArray[0].associate << "\n";

	for (int k = 1; k <= numArray[0].associate;) {
		for (int j = 0; j < 5; j++) {
			std::cout << "| Key:" << numArray[k].key << " Asn:" << numArray[k].associate << "  ";
			k++;
		}
		std::cout << "\n";

	}
}

void CountingSort(dataStruct* numArray, dataStruct* B, int CurrentDigit)
{
	const int Digits = 10;
	int C[Digits], Quotient;
	int* numArrayDigit = new int[numArray[0].associate];
	
	for (int i = 0; i < Digits; i++)
		C[i] = 0;

	for (int j = 1; j <= numArray[0].associate; j++)
	{
		if (CurrentDigit == 1)
			numArrayDigit[j] = numArray[j].key % 10;   // Extracts the 4 from the 14, 9 from 309, etc.
		else
		{  //*** Here we extract the 4 from 3541 and similar.
			int divisor = pow(10, CurrentDigit - 1);
			Quotient = numArray[j].key / divisor;   // For 3541, Quotient = 354.
			numArrayDigit[j] = Quotient % 10;
			//cout << "DEBUG: divisor, Quotient, ADigit[j] are: " << divisor << " " << Quotient << " " << ADigit[j] << endl;
		}

		//cout << "DEBUG: ADigit[j] for j = " << j << " is " << ADigit[j] << endl;
		C[numArrayDigit[j]] = C[numArrayDigit[j]] + 1;
	}
	// C[i] now contains the number of elements equal to i.

	//**** DEBUG: ****
	//for (int j = 1; j <= MaxSize; j++)
	//{
	//    cout << "j = " << j << endl;
	//    cout << "ADigit[j] = " << ADigit[j] << endl;
	//    cout << "C[ADigit[j]] = " << C[ADigit[j]] << endl;
	//}
	//**** END DEBUG ****

	for (int i = 1; i < Digits; i++)
		C[i] = C[i] + C[i - 1];
	// C[i] now contains the numbers of elements less or equal to i.

	for (int j = numArray[0].associate; j > 0; j--)
	{
		B[C[numArrayDigit[j]]] = numArray[j];
		C[numArrayDigit[j]] = C[numArrayDigit[j]] - 1;
	}

	
}

void RadixSort(dataStruct* numArray, int d)
{
	int digit;
	dataStruct* B = new dataStruct[numArray[0].associate];   // Array to temporarily hold the data.
	initArray(B, numArray[0].associate);

	for (digit = 1; digit <= d; digit++)
	{
		CountingSort(numArray, B, digit);
		// Now copy B to A. Note that this wastes some time, O(n) time, where n is the length of the array.
		// Note that the actual time wasted is proportional to n * d, but d is the (small) number of digits, so that the time is still O(n).
		for (int k = 0; k <= numArray[0].associate; k++) {
			numArray[k] = B[k];
		}
	}
}

void insertDataInHashTable(dataStruct* numArray, Hash hashTable) 
{
	for (int i = 1; i <= numArray[0].associate; i++) 
	{
		hashTable.Insert(numArray[i].key, numArray[i].key);
	}
}



void searchForKey(int key, Hash hashTable, dataStruct* numArray)
{
	int index = hashTable.Search(key);
	if (index != -1) 
	{
		std::cout << "Key: " << key << " Data Item: " << numArray[index].associate;
	}
	else
	{
		std::cout << "Key Not Found";
	}
	
	
}

void prompt(Hash hashTable, dataStruct* numArray) 
{
	int userChoice = 0;
	int keyToSearch = 0;
	while (userChoice < 3) {
		userChoice = 0;
		if (userChoice != 1 && userChoice != 2)
		{
			std::cout << "Do You Want to Search for a Key [1], Output all Data [2] or Exit [3]";
			std::cin >> userChoice;
		}
		switch (userChoice) {
		case 1:

			std::cout << "\n Enter an int key 10000 - 29999: ";
			std::cin >> keyToSearch;
			searchForKey(keyToSearch,hashTable,numArray);

			break;
		case 2:

			printData(numArray);

			break;
		}
	}
	
	

	
	
	
}
