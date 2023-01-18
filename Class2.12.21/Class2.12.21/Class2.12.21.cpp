// Class2.12.21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>    // support files, both input and output

using namespace std;

// globals go here

//function prototypes
float getInputKeyboard(void);
void writeOutputScreen(float result);

void writeOutputFile(float result);
//void writeOutputFile(float result, ostream& outputFile);
float getInputFile();
float getInputFile(ifstream& infile);

int main(void){
    float degreesF = 0.0;
    float degreesC = 0.0;

    ifstream aFile;
    aFile.open("data.txt");
    if (aFile.fail()) {
        cout << "Couldn't open input File";
        exit(1);
    }

    degreesF = getInputFile();
    //degreesF = getInputKeyboard();
    /*cout << "Temperature Converter \nInput a temp in degrees F: ";
    cin >> degreesF;*/
    //cout << "You entered " << degreesF; 
    degreesC = (degreesF - 32.0) * 5.0 / 9.0;
    // cout << "Converted temp is: " << degreesC;
    writeOutputScreen(degreesC);
    writeOutputFile(degreesC);

    aFile.close();
    return 0;
}

float getInputKeyboard(void) {
    float temp = 0.0;
    cout << "Temperature Converter \nInput a temp in degrees F: ";
    cin >> temp;

    return temp;
}

void writeOutputScreen(float result) {
    cout << "Converted temp is: " << result;
}

void writeOutputFile(float result) {
    ofstream outfile;
    outfile.open("Output.txt");
    if (outfile.fail()) {
        cout << "Could not open output file" << endl;
        exit(1);
    }
    outfile << "Converted temp is: " << result << "\n\n";
    outfile.close();
}

float getInputFile() {
    ifstream infile;
    float inVal;
    infile.open("data.txt");
    if (infile.fail()) {
        cout << "Couldn't open input file" << endl;
        exit(1);
    }
    cout << "Getting input from file ...\n";
    infile >> inVal;
    infile.close();
    return inVal;
}

float getInputFile(ifstream &infile) {
    float inVal;
    cout << "Getting input from file ...\n";
    infile >> inVal;
    infile.close();
    return inVal;
}
