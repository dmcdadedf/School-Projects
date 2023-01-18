// Author : David McDade    Project: Project4.cpp

// description: This program is designed to take the input from a file called data.txt, 
//and process it. It will take the amount of items bought and multiply it by the price to 
//get a subtotal and then a final total. It will then take the output and display it in 
//the terminal as well as output the data to a file called out.txt.

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream data;
    ofstream out;
    int amount;
    float price, subtotal, total;
    string item;
    char junk;

    data.open("data.txt");              // open and test data.txt

    if (data.fail())
    {
        cout << "Input file data.txt failed to open" << endl;
        exit(1);
    }

    out.open("out.txt");                // open and test out.txt

    if (out.fail())
    {
        cout << "Input file out.txt failed to open" << endl;
        exit(1);
    }



    data >> amount;                 // input first piece of data from first line to see if it fails
    while (!(data.fail()))          
    {
        data.get(junk);             // puts data from file into variables
        data >> price;   
        data.get(junk);  
        data.get(junk);  
        getline(data, item);

        subtotal = price * amount;      // process data
        subtotal += subtotal;

        cout << amount << ", " << price << ", " << subtotal << ", " << item << endl;        // output to terminal and out.txt
        out << amount << ", " << price << ", " << subtotal << ", " << item << endl;

        data >> amount;
    }
    cout << "Total: " << subtotal << endl;
    out << "Total: " << subtotal << endl;

    data.close();               // close files
    out.close();
    return 0;
}
