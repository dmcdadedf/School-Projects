// Class2.15.21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

char convertGrade(float grade);
char convertGradeSwitch(float grade);

int main(void)
{
    char letterGrade = ' ';
    float numberGrade = -1;

    cout << "Enter a number grade (0 - 100): ";
    cin >> numberGrade;
    if (numberGrade > 100 || numberGrade < 0) {
        cout << "Invalid Input" << endl;
        exit(1);
    }
    int t = static_cast<int>(numberGrade);
    letterGrade = convertGradeSwitch(t);
    //if (numberGrade >= 90) {
    //    letterGrade = 'A';
    //} else if (numberGrade >= 80) {
    //    letterGrade = 'B';
    //} else if (numberGrade >= 70) {
    //    letterGrade = 'C';
    //} else if (numberGrade >= 60) {
    //    letterGrade = 'D';
    //} else 
    //    letterGrade = 'F';
    //
    

    cout << "The equivelent letter grade: " << letterGrade << endl;

    return 0;
}

char convertGrade(float grade) {
    char letterGrade = ' ';
    if (grade >= 90) {
        letterGrade = 'A';
    }
    else if (grade >= 80) {
        letterGrade = 'B';
    }
    else if (grade >= 70) {
        letterGrade = 'C';
    }
    else if (grade >= 60) {
        letterGrade = 'D';
    }
    else
        letterGrade = 'F';
    return letterGrade;
}

char convertGradeSwitch(int grade) {
    //int intergerGrade = static_cast<int>(grade);
    char letterGrade = ' ';
    switch (grade) {
    case 100:
    case 99:
    case 98:
    case 97:
    case 96:
    case 95:
    case 94:
    case 93:
    case 92:
    case 91:
    case 90:
        letterGrade = 'A';
        break;
    case 80 : 
        letterGrade = 'B';
        break;
    case 70:
        letterGrade = 'C';
        break;
    case 60:
        letterGrade = 'D';
        break;
    default :
        letterGrade = 'F';
        break;
    }
    return letterGrade;
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
