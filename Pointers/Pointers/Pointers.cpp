// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct S {
    float f;
    S() { f = 0; }
    void print() {
        std::cout << " f " << f << std::endl;
    }
};
typedef S* SPtr;
int main()
{
   /* S s;
    S esses[3];
    for (int i = 0; i < 3; i++) {
        esses[i].print();
    }*/
    /*int x = 5;
    int* p1 = NULL;
    int * p2 = NULL;
    p1 = &x;
    p2 = p1;
    *p2 = 100;
    std::cout << " " << *p1 << std::endl;*/
    int size = 0;
    std::cout << "input the size of the array";
    std::cin >> size;
    SPtr s2 = new S[size];
    delete [] s2;  // how we delete a dynamic array
    for (int i = 0; i < size; i++) {

    }

    SPtr s = new S;
    int* p1 = NULL;
    p1 = new int(-22);
    delete p1; // thing p1 points to is deleted
    //p1 is now pointing to nothing
    p1 = new int(99);   // THIS IS BAD Memory Leak

    return 0;




}

// Pointer not assigned to anything called Dangling Pointer
// Make Sure to not have Dangling Pointers
// If not assigned right away, assign pointer to null
// Can't directly assign pointer to non pointer thing
// Set pointer to address of variable    shown as &variable

// Derefrencing means Get the value of the thing pointed at
// Derefrening opperator is *
// Possible Opperations on pointer: Declare / Set Value & / Dereferance *