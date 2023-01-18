// ClassMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define ARRAY_SIZE 5
#define TOLERANCE .00001
typedef float Matrix[ARRAY_SIZE][ARRAY_SIZE];

void iniMatrix(Matrix f, const int size);

float sumAllElements(Matrix m, const int size);

float sumRowElements(Matrix m, const int size, const int rowOfInterest);

float sumColElements(Matrix m, const int size, const int colOfInterest);

void printMatrix(Matrix f, const int size); 

void averageMatrix(Matrix f, const int size);

float averageMatrixTolerance(Matrix f, const int size);

int main()
{
	Matrix matrix = { {100,100,100,100,100},
					{ 50, 0, 0, 0, 50},
					{ 50, 0, 0, 0, 50},
					{ 50, 0, 0, 0, 50},
					{  0, 0, 0, 0,  0} };
	//iniMatrix(matrix, ARRAY_SIZE);
	float t = FLT_MAX;
	int iterationCount = 0;
	for (; t > TOLERANCE;) {
		cout << "iteration: " << iterationCount++ << "\n";
		t = averageMatrixTolerance(matrix, ARRAY_SIZE);
		printMatrix(matrix, ARRAY_SIZE);
	}



	/*for (int i = 0; i < 200; i++) {
		cout << "Itteration: " << i << "\n";
		averageMatrix(matrix, ARRAY_SIZE);
		printMatrix(matrix, ARRAY_SIZE);

	}*/
	/*float f = sumAllElements(matrix, ARRAY_SIZE);
	float s = sumRowElements(matrix, ARRAY_SIZE, 0);
	float a = sumColElements(matrix, ARRAY_SIZE, 0);
	printMatrix(matrix, ARRAY_SIZE);*/

	return 0;
}

void iniMatrix(Matrix f, const int size) {
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			f[row][col] = row + col;
		}
	}
}

float sumAllElements(Matrix m, const int size) {
	float sum = 0;
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			sum += m[row][col];
		}
	}
	return sum;
}

float sumRowElements(Matrix m, const int size, const int rowOfInterest) {
	float sum = 0;
	for (int col = 0; col < size; col++) {
		sum += m[rowOfInterest][col];
	}
	return sum;
}

float sumColElements(Matrix m, const int size, const int colOfInterest) {
	float sum = 0;
	for (int row = 0; row < size; row++) {
		sum += m[row][colOfInterest];
	}
	return sum;
}

void printMatrix(Matrix f, const int size) {
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			cout << f[row][col] << " ";
		}
		cout << "\n";
	}
}

void averageMatrix(Matrix f, const int size) {
	for (int row = 1; row < size - 1; row++) {
		for (int col = 1; col < size - 1; col++) {
			float t = f[row - 1][col] + f[row + 1][col] + f[row][col + 1] + f[row][col - 1];
			t /= 4.0;
			f[row][col] = t;
		}
	}
}

float averageMatrixTolerance(Matrix f, const int size) {
	float delta = 0;
	for (int row = 1; row < size - 1; row++) {
		for (int col = 1; col < size - 1; col++) {
			float t = f[row - 1][col] + f[row + 1][col] + f[row][col + 1] + f[row][col - 1];
			t /= 4.0;			// new value 
			float temp = t - f[row][col]; // temp holds value
			temp = abs(temp);
			if (delta < temp) {
				delta = temp;
			}
			f[row][col] = t;    // assign the final value to matrix cell
		}
	}
	cout << "Delta: " << delta << "\n";
	return delta;

}