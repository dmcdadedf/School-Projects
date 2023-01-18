//Author : David McDade    Project: Project5.cpp

// This program will use the numbers in the File rainfall.txt as rain amounts for the year. 
// It will put these numbers into an array for easier use. It will then use these to calculate the largest 
// rainfall of the year, smallest rainfall of the year, average rain fall for the year, time rained 3 inches 
// or more over the average rainfall, and time rained 3 inches or more under the average rainfall.
// This program will then output these numbers to the user.

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

void rainfall(float fileNumbers[20]) {         // Given: This takes an empty array in as a parameter
                                               // Task: This function is used to copy the numbers given in the file into an array to easily change the data
    ifstream input;                            // Return: This is a void function so it does not return any variables, but it does referance the array raintotals and changes the values
    input.open("rainfall.txt");

    if (input.fail())
    {
        cout << "Input file rainfall.txt failed to open" << endl;
        exit(1);
    }

    for (int a = 0; a < 20; a++) {
        input >> fileNumbers[a];
    }
    input.close();
}

void calculateTotals(float numbers[20],int& underThree, int& overThree, float& min, float& max, float& average) {
    for (int a = 0; a < 20; a++) {
        if (max < numbers[a]) {                 // Given: This function referances many variables and the array raintotals. This takes in underThree,overThree,min,max,and average.
            max = numbers[a];                   // Task: This function finds the largest number in the given array, the smallest number in the given array, and adds the numbers 
        }                                       //       in the array to the average to divide later. It then also finds the amount of times the numbers were three or more over 
                                                //       the average and the amount of times the numbers were three or under under the average
        if (min > numbers[a]) {                 // Return: This function references several variables, meaning it changes the value of those variables. This does not return any values, however.
            min = numbers[a];

        }
        average += numbers[a];
    }
    average /= 20;

    for (int a = 0; a < 20; a++) {
        if (average + 3 < numbers[a]) {
            overThree++;
        }
        if (average - 3 > numbers[a]) {
            underThree++;
        }
    }
}

void printTotals(int overThree, int underThree, float min, float max, float average) {
    cout << "Lowest rainfall amount: " << min << " inches" << endl << "Highest rainfall amount : " << max << " inches" << endl << "Average rainfall amount : " << average << " inches" << endl;
    cout << "Number of rainfall amounts under " << average - 3 << " inches : " << underThree << endl << "Number of rainfall amounts over " << average + 3 << " inches : " << overThree << endl;
}   
                                                // Given: This function takes 5 parameters. It takes overThree, underThree, min, max, and average.
                                                // Task: This prints the values of the variables
                                                // Return: This function does not return any values
                                              
int main()
{
    
    float raintotals[20];
    float max = 0.0, min = 10000.0, average = 0.0;
    int underThree = 0, overThree = 0;

    rainfall(raintotals);

    calculateTotals(raintotals, underThree, overThree, min, max, average);
   
    printTotals(underThree, overThree, min, max, average);

    return 0;
}
