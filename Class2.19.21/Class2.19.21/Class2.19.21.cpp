// Class2.19.21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace ::std;
int main(void){
    for (int n = 0; n < 5 ; n++) {
        for (int t = 0; t < n; t++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}


