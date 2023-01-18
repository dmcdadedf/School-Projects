// Project2DavidMcDade.cpp
// Authors: David McDade	Partener doing STL code: Patrick McDonagh
//
// Date: October 28, 2021
//
//Program: This program prompts the user for a number integer greater than 0 or to enter 0 to end the program. If the user enters a number less than 0 they will be reprompted.
//		   The program takes this number and using the Zybook stack, it converts the number from base 10 to Hexadecimal. The program then outputs the Hexadecimal to the user.
//		   It then reprompts the user for a number integer greater than 0 or to enter 0 to end the program.

#include <iostream>
#include "Stack.h"
using namespace std;
#define MAX 2147483647

// Given:  None
//
// Task:  To prompt the user to enter a number integer greater than 0 or to enter 0 to end the program.
// 
// Return: The user input of a number integer
int askForNum();

// Given:  num -  a user input number integer
//		   numStack - an empty stack of numbers
//
// Task:  To convert the base 10 num to a base 16 hexadecimal number. This will push each number in reverse order in the stack.
// 
// Return: numStack - A stack with the information to print a hexadecimal number.
void convertToHex(int num, Stack &numStack);

// Given:  numStack - A Stack with the information to print a hexadecimal number
//		   hexNumber - A string that stores the hexadecimal number
//		   originalNum - The integer number the user originally entered into the prompt
//
// Task:  To Pop the numbers stored in the stack to create a hexadecimal number stored in the hexNumber string
// 
// Return: hexNumber - the hexadecimal number
//		   numStack - the now empty numStack
void printHexNumber(Stack &numStack, string& hexNumber, int originalNum);

// Given:  numStack - a stack with integers stored
//
// Task:  To pop all numbers off of the stack to return it to an empty stack
// 
// Return: numStack - an empty stack
void deleteStack(Stack &numStack);

int main(void)
{
	Stack numStack;
	int userInput = 0;
	string hexNum = "";

	userInput = askForNum();					//prompts user for a number or to end the program
	
	while (userInput < 0) {							// This prompts the user to enter a positive integer if they entered 
		cout << "This is not a Positive Integer, ";
		userInput = askForNum();
	}

	while (userInput > 0 && userInput < MAX) {		//While the user input does not equal 0 and is less than the max int to prevent an overflow error
		convertToHex(userInput, numStack);
		printHexNumber(numStack, hexNum, userInput);
		deleteStack(numStack);
		userInput = askForNum();
		while (userInput < 0) {
			cout << "This is not a Positive Integer, ";
			userInput = askForNum();
		}
	}
	return 0;
}

int askForNum() {
	int input = -1;				
	cout << "Please enter a Positive integer, or enter a 0 to Exit. \n";
	cin >> input;
	return input;
}



 void convertToHex(int num, Stack &numStack) {
	int remainder = 1;
	while (num > 0) {
		remainder = num % 16;
		numStack.Push(remainder);
		num /= 16;
	}
}

void printHexNumber(Stack &numStack, string &hexNumber, int originalNum) {
	hexNumber = "";
	int base10Num = 0;
	while (numStack.getSize() > 0) {
		base10Num = numStack.Pop();
		if (base10Num == 0)
			hexNumber += "0";
		else if (base10Num == 1)
			hexNumber += "1";
		else if (base10Num == 2)
			hexNumber += "2";
		else if (base10Num == 3)
			hexNumber += "3";
		else if (base10Num == 4)
			hexNumber += "4";
		else if (base10Num == 5)
			hexNumber += "5";
		else if (base10Num == 6)
			hexNumber += "6";
		else if (base10Num == 7)
			hexNumber += "7";
		else if (base10Num == 8)
			hexNumber += "8";
		else if (base10Num == 9)
			hexNumber += "9";
		else if (base10Num == 10)
			hexNumber += "A";
		else if (base10Num == 11)
			hexNumber += "B";
		else if (base10Num == 12)
			hexNumber += "C";
		else if (base10Num == 13)
			hexNumber += "D";
		else if (base10Num == 14)
			hexNumber += "E";
		else if (base10Num == 15)
			hexNumber += "F";
	}
	cout << "The Number " << originalNum  << " in Hexadecimal is: "<< hexNumber << endl << endl;
}

void deleteStack(Stack &numStack) {
	while (numStack.getSize() > 0) {
		numStack.Pop();
	}
}
