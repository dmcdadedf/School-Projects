//	CS312 Main Project Part C
//  Created 11/05/2022 by David McDade
// 
// This program reads data in from a file and stores it into an array located on the heap.
// Then the array is sorted using radix sort and the indexes are stored in a hashtable with a hash function associated to the key
// The user is then prompted to either search for a specific key, output all keys and associated data to an output file in ascending order, monitor the hash table, or exit the program.
#pragma region header
#include <iostream>
#include <fstream> 
#include<string>

using namespace std;

const int prime = 3793;

struct dataStruct {
	//member variables
	int key;
	int associate;
};

struct nodeType
{
	int structIndex;
	int key;
	nodeType* nextPtr;
};

typedef nodeType* nodePtrType;
typedef nodePtrType hashTableType[prime];


#pragma endregion

#pragma region Function Declarations

// preconditions: -
// postconditions: the array is initiatied to make all variables stored in the dataStruct in each index 0 and the first index of the array is set to the array size
void initArray(dataStruct* numArray, int size);

// preconditions: -
// postconditions: the Hash Table is initiatied. All buckets nextPtr is set to null, all int variables are set to int 0.
void initializeTable(hashTableType hashTable);

// preconditions: -
// postconditions: the int array numOfBuckets is initiatied. All indexes are set to int 0.
void initNumOfBuckets(int* numOfBuckets);

//preconditions - 
//postconditions - returns the number of items in the file
int getFileSize();

// preconditions - all arrays have been initialized
// postconditions - writes file information into the array starting at index 1
void readData(dataStruct* numArray);

// preconditions: An array of dataStructs with keys and the maximum number of digits in each integer
// postconditions: a sorted array of dataStructs in assending order by key.
void RadixSort(dataStruct* numArray, int d);

// preconditions: An array of dataStructs to be sorted and a temp array of the same type as well as the current digit number being sorted
// postconditions: the temp array containing data from the input array sorted in ascending order.
void CountingSort(dataStruct* numArray, dataStruct* B, int CurrentDigit);

// preconditions: an initialized Hash Table, an array of dataStructs with key values and associated data.
// postconditions: a hash table with keys and indexes of the location in the sorted array stored at the location returned by the hash function on the key
void insertTable(hashTableType hashTable, dataStruct* numArray);

// preconditions: an initialized int key
// postconditions: a hash value of the key is returned using a hash function key of the hash table size.
int hashFn(int key);

// preconditions: a filled and sorted dataStruct array, a filled hash table, and an initialized int array numBucket 
// postconditions: if selected in user input, an output file with the sorted contents of numArray
void prompt(dataStruct* numArray, hashTableType hash, int* numOfBuckets);

// preconditions: a hash table, a valid key between the given range of 10000 - 29999
// postconditions: the int index of the key in the sorted dataStruct array
int findTable(hashTableType hashTable, int key);

//preconditions - the array is filed with information and not empty
//postconditions - prints the information from the array 10 items per line
void printDataToFile(dataStruct* numArray);

// preconditions: A filled Hash Table, An initialized int array numBuckets
// postconditions: numBuckets has the number of empty buckets in numBucket[0], the number of buckets that are not empty in numBucket[1], the number bucket of the largest link of nodes in numBucket[2], 
//					the number of nodes in the largest linked list in numBucket[3], and the number of nodes with 0 links, 1 link, 2 links... in the following indexes in sequential order
void monitorTable(hashTableType hashTable, int* numBuckets);

// preconditions: a hash table with data
// postconditions: the hash table is deleted
void emptyTable(hashTableType hashTable);

// preconditions: a hash table with data, a dataStruct array with data, an int array with data
// postconditions: all data and memory allocation is deleted.
void deleteAll(hashTableType hashTable, dataStruct* numArray, int* numOfBuckets);

#pragma endregion

int main(void)
{
    int fileSize = getFileSize();

	dataStruct* numArray = new dataStruct[fileSize];

	int* numOfBuckets = new int[14];

	hashTableType hashTable;

	initArray(numArray, fileSize);

	initializeTable(hashTable);

	initNumOfBuckets(numOfBuckets);

	readData(numArray);

	RadixSort(numArray, 5);

	insertTable(hashTable, numArray);


	prompt(numArray,hashTable, numOfBuckets);

	return 0;
}

#pragma region Function Implementations

void initArray(dataStruct* numArray, int size) {

	numArray[0].key = 0;
	numArray[0].associate = size;

	for (int i = 1; i <= size; i++) {
		numArray[i].key = 0;
		numArray[i].associate = 0;
		//numArray[i].index = 0;
	}
}

void initializeTable(hashTableType hashTable)
{
	for (int k = 0; k < prime; k++)
		hashTable[k] = NULL;
}

void initNumOfBuckets(int* numOfBuckets)
{
	for (int f = 0; f < 14; f++)
	{
		numOfBuckets[f] = 0;
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
		for (int k = 1; k <= numArray[0].associate; k++) {
			numArray[k] = B[k];
		}
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

void insertTable(hashTableType hashTable, dataStruct* numArray)
{
	int location;
	string junk;
	nodePtrType nextPtr, nodePtr;
	for (int i = 1; i < numArray[0].associate; i++) {

		location = hashFn(numArray[i].key);

		if (hashTable[location] == NULL)
		{
			try
			{
				nodePtr = new nodeType;
			}
			catch (bad_alloc)
			{
				// Here we give up and exit the program.
				cerr << "Memory allocation error! Exiting the program.\n" << endl;
				cerr << "Press Enter" << endl;
				emptyTable(hashTable);
				getline(cin, junk, '\n');
				exit(1);
			}

			// Insert as the only node on the list:
			nodePtr->key = numArray[i].key;
			nodePtr->structIndex = i;
			nodePtr->nextPtr = NULL;
			hashTable[location] = nodePtr;
		}
		else   // hashTable[location] is not NULL
		{
			nextPtr = hashTable[location];
			try
			{
				nodePtr = new nodeType;
			}
			catch (bad_alloc)
			{
				// Here we give up and exit the program.
				cerr << "Memory allocation error! Exiting the program.\n" << endl;
				cerr << "Press Enter" << endl;
				emptyTable(hashTable);
				getline(cin, junk, '\n');
				exit(1);
			}

			// Insert at front of list:
			nodePtr->key = numArray[i].key;
			nodePtr->structIndex = i;
			nodePtr->nextPtr = nextPtr;
			hashTable[location] = nodePtr;
			//std::cout << "Collision: Index " << nodePtr->structIndex << " Key " << nodePtr->key;
		}

	}
}

int hashFn(int key)
{
	return key % prime;
}

void prompt(dataStruct* numArray, hashTableType hash, int* numOfBuckets)
{
	int userChoice = 0;
	int keyToSearch = 0;
	int structIndex = 0;
	while (userChoice < 4)
	{
		userChoice = 0;
		keyToSearch = 0;
		structIndex = 0;
		if (userChoice != 1 && userChoice != 2 && userChoice != 3)
		{
			std::cout << "Do You Want to Search for a Key [1], Output all Data to Output File [2], Monitor Table[3], or Exit [4] \n";
			std::cin >> userChoice;
		}
		switch (userChoice) {
		case 1:

			std::cout << "Choose a Key to Search for from 10000 - 29999 \n";
			cin >> keyToSearch;

			while (keyToSearch < 10000 || keyToSearch > 29999) {
				std::cout << "Invalid Key: Key Must be from 10000 - 29999 \n";
				std::cout << "Choose a Key to Search for from 10000 - 29999\n";
				cin >> keyToSearch;
			}

			structIndex = findTable(hash, keyToSearch);
			if (structIndex == -1) {
				std::cout << "Key Not Found\n";
			}
			else
			{
				std::cout << "The key: " << keyToSearch << " has the value stored of: " << numArray[structIndex].associate << endl;
			}

			break;
		case 2:
			printDataToFile(numArray);
			break;
		case 3:
			monitorTable(hash, numOfBuckets);
			break;
		case 4:
			deleteAll(hash, numArray, numOfBuckets);
			break;
		}
	}



}

int findTable(hashTableType hashTable, int key)
{
	int location;
	nodePtrType currentPtr;

	location = hashFn(key);
	currentPtr = hashTable[location];

	if (currentPtr == NULL)
		return -1;    // To indicate that str was not found.

	while (currentPtr != NULL)
	{
		if (currentPtr->key == key)
			return currentPtr->structIndex;  // Here is where str was found.
		else
			currentPtr = currentPtr->nextPtr;
	}

	return -1;   // To indicate that str was not found.
}

void printDataToFile(dataStruct* numArray) {

	std::ofstream outFile;
	outFile.open("Output.txt");
	if (outFile.fail()) {
		std::cout << "Could not open data file\n";
		return;
	}

	outFile << "Size of array: " << numArray[0].associate << "\n";

	for (int k = 1; k <= numArray[0].associate;) {
		for (int j = 0; j < 5; j++) {
			outFile << "| Key:" << numArray[k].key << " Asn:" << numArray[k].associate << "  ";
			k++;
		}
		outFile << "\n";

	}
	outFile.close();
	std::cout << "Results were written to File \n";
}

void monitorTable(hashTableType hashTable, int* numBuckets)
{
	int location;
	int temp = 0;
	float average = 0;
	nodePtrType currentPtr;


	for (location = 0; location < prime; location++)
	{
		temp = 0;
		currentPtr = hashTable[location];

		if (currentPtr == NULL) {
			numBuckets[0]++;
		}
		else
		{
			while (currentPtr != NULL)
			{
				temp++;
				currentPtr = currentPtr->nextPtr;
			}

			numBuckets[1]++;

			if (temp > numBuckets[3]) {
				numBuckets[2] = location;
				numBuckets[3] = temp;
			}

			numBuckets[temp + 3] += 1;

		}
	}

	average = numBuckets[1];
	average /= prime;
	average *= 100;

	std::cout << "Buckets with 0 nodes : " << numBuckets[0] << endl;
	for (int f = 4; f < 14; f++)
	{
		if (numBuckets[f] != 0) {
			std::cout << "Buckets with " << f - 3 << " nodes: " << numBuckets[f] << "\n";
		}
	}
	std::cout << endl;
	std::cout << "Location " << numBuckets[2] << " has the most links with " << numBuckets[3] << " \n";
	std::cout << "The percentage of locations with 1 or more links is  %" << average << endl << endl;
	

}

void emptyTable(hashTableType hashTable) {
	nodePtrType currentPtr, savedPtr;

	for (int k = 0; k < prime; k++)
	{
		currentPtr = hashTable[k];
		// Clear out the list at index k:
		while (currentPtr != NULL)
		{
			savedPtr = currentPtr->nextPtr;
			delete currentPtr;
			currentPtr = savedPtr;
		}
	}
}

void deleteAll(hashTableType hashTable, dataStruct* numArray, int* numOfBuckets)
{

	emptyTable(hashTable);

	cout << "The hash table has been emptied" << endl;

	//delete[] numArray;
	cout << "numArray has been deleted." << endl;

	delete[] numOfBuckets;
	cout << "numOfBuckets has been deleted." << endl;

}

#pragma endregion


