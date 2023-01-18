// CS111Project2-McDade.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define ARRAY_SIZE 15
#define TOLERANCE .001
typedef float Matrix[ARRAY_SIZE][ARRAY_SIZE];


//precondition: matrix is the simulation, size is number of columns and rows
//postcondition: matrix is initialized to border temperature (given by the user). 
// Assume all border row and column elements are set to the border temperature (150)
// All non-border elements are all set to zero.
void initializeSimulation(Matrix matrix, int size);

//precondition: matrix is the simulation, size is number of columns and rows, 
// runs is the of simulation runs.
//postcondition: matrix contains the simulation values after the simulation completes 
// runs runs. 
float simulate(Matrix matrix, int size);

//precondition: matrix is the simulation, size is number of columns and rows
//postcondition: the contents of the matrix are output to the screen
// set precision to one and width to four
void printSimulationResults(Matrix matrix, int size);

int main(void)
{ 
	Matrix matrix;
	float t = FLT_MAX;
	int iterationCount = 0;
	initializeSimulation(matrix, ARRAY_SIZE);

	for (; t > TOLERANCE;iterationCount++) 
		t = simulate(matrix, ARRAY_SIZE);
	cout << "Iterations it took: " << iterationCount << endl;
	printSimulationResults(matrix, ARRAY_SIZE);
	
    return 0;
}

void initializeSimulation(Matrix matrix, int size) {
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			if (row == 0) {
				matrix[row][col] = 150;
			}
			else if(row == size - 1){
				matrix[row][col] = 150;
			}
			else if (col == 0 || col == size - 1) {
				matrix[row][col] = 150;
			}
			else
				matrix[row][col] = 0;
		}
	}
}


float simulate(Matrix matrix, int size) {
		float delta = 0;
		for (int row = 1; row < size - 1; row++) {
			for (int col = 1; col < size - 1; col++) {
				float t = matrix[row - 1][col] + matrix[row + 1][col] + matrix[row][col + 1] + matrix[row][col - 1];
				t /= 4.0;			// new value 
				float temp = t - matrix[row][col]; // temp holds value
				temp = abs(temp);
				if (delta < temp) {
					delta = temp;
				}
				matrix[row][col] = t;    // assign the final value to matrix cell
			}
		}
		return delta;

	
}

void printSimulationResults(Matrix matrix, int size) {
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			cout  << matrix[row][col] << " ";
		}
		cout << "\n";
	}
}