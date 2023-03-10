// CS221Homework1.cpp
//
// Primary author: Br. David Carlson         Other authors: Patrick McDonagh, David McDade 
//
// Date: Sept 14, 2021
//
// This program runs a series of tests to estimate the running time for sorting some short arrays of integers and then two
// longer arrays. Selection sort and quicksort are compared in this fashion. The actual sorted data are shown for the two
// short arrays but not for the long array of 1000 and 2000 items. The number of comparisons and the number of swaps used
// in each sort are reported on the screen.

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int length = 28;
const int doubleLength = 56;

// Given:  numbers - an array of integers
//         arraySize - the number of items in the numbers array
// Task:   to use selection sort to sort into ascending order the data in the numbers array and to find the
//         number of comparisons and the number of swaps used in this sort.
// Return: numbers - the sorted array of integers
//         numCompares - the number of comparisons used by the sort
//         numSwaps - the number of swaps used by the sort
void selectionSort(int numbers[], int arraySize, int& numCompares, int& numSwaps);

// Given:  numbers - an array of integers
//         startIndex - the starting index for the section to be sorted in the array numbers
//         endIndex - the ending index for the section to be sorted in the array numbers
// Task:   to use the ZyBook version of quicksort to sort into ascending order the specified section in the
//         numbers array and to find the number of comparisons and the number of swaps used in this.
// Return: numbers - the original array of integers but with the specified section of it now sorted
//         numCompares - the number of comparisons used by the sort
//         numSwaps - the number of swaps used by the sort
void quickSort(int numbers[], int startIndex, int endIndex, int& numCompares, int& numSwaps);

// Given:  numbers - an array of integers
//         arraySize - the number of items in the numbers array
// Task:   to use the ZyBook version of quicksort to sort into ascending order the data in the numbers array
//         and to find the number of comparisons and the number of swaps used in this sort.
// Return: numbers - the sorted array of integers
//         numCompares - the number of comparisons used by the sort
//         numSwaps - the number of swaps used by the sort
void quickSortDriver(int numbers[], int arraySize, int& numCompares, int& numSwaps);

// Given:  numbers - an array of integers
//         startIndex - the starting index for the section to be sorted in the array numbers
//         endIndex - the ending index for the section to be sorted in the array numbers
// Task:   to select as the pivot the midpoint of the section to be sorted and to partition the section of the numbers
//         array from index startIndex to index endIndex so that numbers <= the pivot are on the left, numbers >= the pivot
//         are on the right, and the pivot is between them.
// Return: numbers - the original array of integers but with the specified section of it now partitioned as just described
//         numCompares - the number of comparisons used in this process
//         numSwaps - the number of swaps used in this process
int Partition(int numbers[], int startIndex, int endIndex, int& numCompares, int& numSwaps);


//***** Write the comment section and the 1-line function declaration for your "simpler" quicksort driver function here.
//Array of numbers carry out the size of the array indicating how many numbers there are, along with referring to the total number of swaps and comparisons within the numbers                     Patrick McDonagh
void simplerQuickSortDriver(int numbers[], int arraySize, int& numCompares, int& numSwaps);
//***** Write the comment section and the 1-line function declaration for your "simpler" quicksort function here.
//Array of numbers range from the startIndex to the endIndex, while the numCompares and numSwaps refer back to the quicksort integer                                                      Patrick McDonagh
void simplerQuickSort(int numbers[], int startIndex, int endIndex, int& numCompares, int& numSwaps);
//***** Write here the comment section and the 1-line function declaration for your partition function that is used by your            
//***** simpler quicksort function here.
//Partitions the array of numbers from the startIndex to the endIndex, while the numCompares and numSwaps refer back to the partition integer               Patrick McDonagh
int simplerPartition(int numbers[], int startIndex, int endIndex, int& numCompares, int& numSwaps);







// Given:  dataArray - an array of integers
//         arraySize - the number of items in the dataArray
// Task:   to print the numbers in dataArray in the order in which they are found in dataArray
// Return: nothing is returned in the function name or in any of the parameters
void printArray(int dataArray[], int arraySize);

// Given:  originalArray - an array of integers
//         numItems - the number of items in originalArray
// Task:   to copy all of the numbers from originalArray to the same locations in newArray.
//         (It is assumed that both arrays are of the same length.)
// Return: newArray - now containing an identical copy of all of the number that are in originalArray
void copyArray(int originalArray[], int newArray[], int numItems);


int main()
{
    int compares, swaps;
    // Create an array of numbers to sort
    int numbers[length] = { 10, 512, 99, 2, 78, 4, 289, 45, 32, 38, 866, 7, 44, 49, 673, 55, 91, 11, 405, 777, 921, 19, 1234,
       1024, 56, 765, 528, 4321 };

    int numbersCopy[length];
    int numbersLongCopy[doubleLength];

    copyArray(numbers, numbersCopy, length);

    // Display the contents of the array
    cout << "UNSORTED ARRAY:" << endl;
    printArray(numbers, length);
    cout << endl << endl;

    selectionSort(numbersCopy, length, compares, swaps);

    cout << "ARRAY SORTED WITH SELECTION SORT:" << endl;
    printArray(numbersCopy, length);
    cout << endl << "Number of comparisons: " << compares << endl << "Number of swaps: " << swaps << endl << endl;

    // Next, we make the array twice as long:
    int numbersLong[doubleLength] = { 10, 512, 99, 2, 1178, 4, 289, 45, 32, 38, 866, 7, 44, 49, 673, 55, 91, 1111, 405, 777,
        921, 19, 1234, 1024, 56, 765, 528, 4321, 47, 666, 93, 770, 1, 15, 942, 79, 46, 20, 828, 18, 990, 264, 705, 61, 94, 80,
        504, 709, 848, 5, 2166, 32, 987, 2222, 1049, 38 };

    copyArray(numbersLong, numbersLongCopy, doubleLength);

    // Display the contents of the array
    cout << "UNSORTED ARRAY TWICE AS LONG:" << endl;
    printArray(numbersLong, doubleLength);
    cout << endl << endl;

    selectionSort(numbersLongCopy, doubleLength, compares, swaps);

    cout << "ARRAY TWICE AS LONG SORTED WITH SELECTION SORT:" << endl;
    printArray(numbersLongCopy, doubleLength);
    cout << endl << "Number of comparisons: " << compares << endl << "Number of swaps: " << swaps << endl << endl;

    //------------------- Switch to a different sort: -----------------------------------------------------

    copyArray(numbers, numbersCopy, length);
    quickSortDriver(numbersCopy, length, compares, swaps);

    cout << "ARRAY SORTED WITH ZYBOOK QUICKSORT:" << endl;
    printArray(numbersCopy, length);
    cout << endl << "Number of comparisons: " << compares << endl << "Number of swaps: " << swaps << endl << endl;

    copyArray(numbersLong, numbersLongCopy, doubleLength);
    quickSortDriver(numbersLongCopy, doubleLength, compares, swaps);

    cout << "ARRAY TWICE AS LONG SORTED WITH ZYBOOK QUICKSORT:" << endl;
    printArray(numbersLongCopy, doubleLength);
    cout << endl << "Number of comparisons: " << compares << endl << "Number of swaps: " << swaps << endl << endl;

    //------------------- Read in data and sort the arrays of 1000 and then 2000 items: ------------------------
    //
    // To avoid allocating space for an array of 1000 items and another of 2000, we will allocate space for only the
    // array of 2000 and just half fill it when working with the 1000 items.
    const int newLength = 2000;
    int halfLength = 1000;

    int newNumbers[newLength];
    fstream file1, file2;

    file1.open("numbers1.txt", ios::in);
    if (file1.fail())
    {
        cerr << "Could not open file numbers1.txt for reading" << endl;
        exit(1);
    }

    // Put 1000 items into this array:
    for (int k = 0; k < halfLength; k++)
        file1 >> newNumbers[k];

    file1.close();

    selectionSort(newNumbers, halfLength, compares, swaps);

    cout << "1000-ITEM ARRAY SORTED WITH SELECTION SORT:" << endl;
    cout << endl << "Number of comparisons: " << compares << endl << "Number of swaps: " << swaps << endl << endl;

    file1.open("numbers1.txt", ios::in);
    if (file1.fail())
    {
        cerr << "Could not open file numbers1.txt for reading" << endl;
        exit(1);
    }

    // Put the same 1000 items back at their original positions:
    for (int k = 0; k < halfLength; k++)
        file1 >> newNumbers[k];

    file1.close();

    quickSortDriver(newNumbers, halfLength, compares, swaps);

    cout << "1000-ITEM ARRAY SORTED WITH ZYBOOK QUICKSORT:" << endl;
    cout << endl << "Number of comparisons: " << compares << endl << "Number of swaps: " << swaps << endl << endl;

    // Now we do the same processing on an array of 2000 items:

    file2.open("numbers2.txt", ios::in);
    if (file2.fail())
    {
        cerr << "Could not open file numbers2.txt for reading" << endl;
        exit(1);
    }

    for (int k = 0; k < newLength; k++)
        file2 >> newNumbers[k];

    file2.close();

    selectionSort(newNumbers, newLength, compares, swaps);

    cout << "2000-ITEM ARRAY SORTED WITH SELECTION SORT:" << endl;
    cout << endl << "Number of comparisons: " << compares << endl << "Number of swaps: " << swaps << endl << endl;

    file2.open("numbers2.txt", ios::in);
    if (file2.fail())
    {
        cerr << "Could not open file numbers2.txt for reading" << endl;
        exit(1);
    }

    // Restore the unsorted data:
    for (int k = 0; k < newLength; k++)
        file2 >> newNumbers[k];

    file2.close();

    quickSortDriver(newNumbers, newLength, compares, swaps);

    cout << "2000-ITEM ARRAY SORTED WITH ZYBOOK QUICKSORT:" << endl;
    cout << endl << "Number of comparisons: " << compares << endl << "Number of swaps: " << swaps << endl << endl;

    // Final tests comparing the Zybook Quicksort (just seen above) and a simpler Quicksort:

    //***** Fill in here the code to again read the data from numbers2.txt and place them into the newNumbers array.          
    //***** This is so that we can run another sorting test on the exact same numbers.
    //***** Then call your driver function for the simpler quicksort so that it does sort the exact same numbers.               Patrick McDonagh
    //***** Then report on the number of comparisons and the number of swaps, exactly like in the previous report.              

    //------------------- Sometimes we sort an array just to be sure the data is in order : ---------------------
    quickSortDriver(newNumbers, newLength, compares, swaps);

    cout << "2000-ITEM ARRAY SORTED AGAIN WITH ZYBOOK QUICKSORT TO BE SURE IT IS STILL IN ORDER:" << endl;
    cout << endl << "Number of comparisons: " << compares << endl << "Number of swaps: " << swaps << endl << endl;


    //***** Fill in here the code to again read the data from numbers2.txt and place them into the newNumbers array.            Patrick McDonagh
    //***** This is so that we can run another sorting test on the exact same numbers.

    file2.open("numbers2.txt", ios::in);

    if (file2.fail())
    {
        cerr << "Could not open file numbers2.txt for reading" << endl;
        exit(1);
    }

     // Restore the unsorted data:
    for (int k = 0; k < newLength; k++)
        file2 >> newNumbers[k];

    file2.close();
    //***** Then call your driver function for the simpler quicksort so that it does sort the exact same numbers.           David McDade
    simplerQuickSortDriver(newNumbers, newLength, compares, swaps);     

    //***** Then report on the number of comparisons and the number of swaps, exactly like in the previous report.          David McDade
    cout << "2000-ITEM ARRAY SORTED WITH SIMPLER QUICKSORT:" << endl;
    cout << endl << "Number of comparisons: " << compares << endl << "Number of swaps: " << swaps << endl << endl;
    

    //***** Then sort the same array again to verify that it is in order.                                                   David McDade
    simplerQuickSortDriver(newNumbers, newLength, compares, swaps);

    //***** Then report on the number of comparisons and the number of swaps, exactly like in the previous report.          David McDade
    cout << "2000-ITEM ARRAY SORTED AGAIN WITH SIMPLER QUICKSORT TO BE SURE IT IS STILL IN ORDER:" << endl;
    cout << endl << "Number of comparisons: " << compares << endl << "Number of swaps: " << swaps << endl << endl;

    //***** Be sure to label things clearly so that we can tell what action the number of swaps and number of
    //***** comparisons refers to.

    return 0;
}


void selectionSort(int numbers[], int arraySize, int& numCompares, int& numSwaps)
{
    numCompares = 0;
    numSwaps = 0;
    for (int i = 0; i < arraySize - 1; i++)
    {
        // Find index of smallest remaining element
        int indexSmallest = i;
        for (int j = i + 1; j < arraySize; j++)
        {
            numCompares++;
            if (numbers[j] < numbers[indexSmallest])
                indexSmallest = j;
        }

        // Swap numbers[i] and numbers[indexSmallest]
        numSwaps++;
        int temp = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = temp;
    }
}


void printArray(int dataArray[], int arraySize)
{
    for (int i = 1; i < arraySize; i++)
        cout << setw(5) << dataArray[i];
}


void copyArray(int originalArray[], int newArray[], int numItems)
{
    for (int k = 0; k < numItems; k++)
        newArray[k] = originalArray[k];
}


int Partition(int numbers[], int startIndex, int endIndex, int& numCompares, int& numSwaps)
{
    // Select the middle value as the pivot.
    int midpoint = startIndex + (endIndex - startIndex) / 2;
    int pivot = numbers[midpoint];

    // low and high indices start at the ends of the partition and move toward each other:
    int low = startIndex;
    int high = endIndex;

    bool done = false;
    while (!done)
    {
        // Increment low while numbers[low] < pivot
        while (numbers[low] < pivot)
        {
            numCompares++;
            low = low + 1;
        }
        numCompares++;   // To count the compare that ended the loop

        // Decrement high while pivot < numbers[high]
        while (pivot < numbers[high])
        {
            numCompares++;
            high = high - 1;
        }
        numCompares++;   // To count the compare that ended the loop

        // If low and high have crossed each other, the loop is done. If not, the elements
        // are swapped, low is incremented and high is decremented.
        if (low >= high)  // You could also count this comparison, but it is likely faster since there is no array indexing.
            done = true;
        else
        {
            // Do a swap. Sometimes this will swap a number with itself, which is unnecessary work.
            numSwaps++;
            int temp = numbers[low];
            numbers[low] = numbers[high];
            numbers[high] = temp;
            low = low + 1;
            high = high - 1;
        }
    }

    // "high" is the last index in the left partition.
    return high;
}


void quickSort(int numbers[], int startIndex, int endIndex, int& numCompares, int& numSwaps)
{
    // Only sort if at least 2 elements exist
    if (endIndex <= startIndex)
        return;

    // Partition the array
    int high = Partition(numbers, startIndex, endIndex, numCompares, numSwaps);

    // Recursively sort the left partition
    quickSort(numbers, startIndex, high, numCompares, numSwaps);

    // Recursively sort the right partition
    quickSort(numbers, high + 1, endIndex, numCompares, numSwaps);
}


void quickSortDriver(int numbers[], int arraySize, int& numCompares, int& numSwaps)
{
    numCompares = 0;
    numSwaps = 0;
    quickSort(numbers, 0, arraySize - 1, numCompares, numSwaps);
}


// Go to https://cis.stvincent.edu/html/tutorials/swd/recur/recur.html and half way through that web page you will come
// to a somewhat simpler version of quicksort. Take that code and package up the partioning of the array as a function
// named simplerPartition. Package up the quicksort function itself as simplerQuickSort. Then write a driver function
// like the one used above for the ZyBook quicksort, but have your driver call this "simpler" version of quicksort.
// In the following 3 functions make sure that you are keeping track of, and returning in appropriate parameters, the
// number of comparisons and the number of swaps used.

// Write your code for simplerPartition here:

int simplerPartition(int numbers[], int startIndex, int endIndex, int& numCompares, int& numSwaps)                       //David McDade
{
    int Pivot, Left, Right;

    Pivot = numbers[startIndex];
    Left = startIndex;
    Right = endIndex;

    while (Left < Right)
    {
        // scan left to right
        while ((numbers[Left] <= Pivot) && (Left < Right)) {
            numCompares++;
            Left++;
        }
        numCompares++;
        // scan right to left
        while (numbers[Right] > Pivot) {
            numCompares++;
            Right--;
        }
        numCompares++;
        if (Left < Right) {
            // swap
            numSwaps++;
            int temp = numbers[Left];
            numbers[Left] = numbers[Right];
            numbers[Right] = temp;
        }
    }

    numbers[startIndex] = numbers[Right];
    numbers[Right] = Pivot;
    return Right;  // return the pivot index
}


// Write your code for simplerQuickSort here:

void simplerQuickSort(int numbers[], int startIndex, int endIndex, int& numCompares, int& numSwaps)                 // David McDade
{
    int PivotIndex;

    if (startIndex < endIndex)
    {
        PivotIndex = simplerPartition(numbers, startIndex, endIndex, numCompares, numSwaps);
        simplerQuickSort(numbers, startIndex, PivotIndex - 1, numCompares, numSwaps);   // sort left side
        simplerQuickSort(numbers, PivotIndex + 1, endIndex, numCompares, numSwaps);   // sort right side
    }
}


// Write your code for simplerQuickSortDriver here:

void simplerQuickSortDriver(int numbers[], int arraySize, int& numCompares, int& numSwaps)                  //David McDade
{
    numCompares = 0;
    numSwaps = 0;
    simplerQuickSort(numbers, 0, arraySize - 1, numCompares, numSwaps);
}
