// StructClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//#include <cmath>
//#include <string>
//using namespace std;
//
//
//
//struct Vector {    // Scope is stuct
//    float x;
//    float y;
//    float z;
//    float length;
//
//    Vector() {
//        x = 0;
//        y = 0;
//        z = 0;
//        length = 0;
//    }
//
//    Vector(float _x, float _y, float _z, float _length) { x = _x; y = _y; z = _z; length = _length; }
//
//    void Print() {
//        cout << "x: " << x << " y: " << y << " z: " << z << endl;  // direct access to the member variables
//    }
//    void Length() {  // the length of the vector defined by Pythagorian Theorem
//        float t = pow(x, 2) + pow(y, 2) + pow(z, 2);
//        length = sqrt(t);
//    }
//    void Normalize(){  // calculates pure direction
//        Length();
//        float sum = x + y + z;
//        if (sum != 0) {
//            x = x / length;
//            y = y / length;
//            z = z / length;
//        }else {
//            cout << "Error can't normalize a zero vector" << endl;
//        }
//        
//
//    }
//};

#include "Vector.h"
#include "S.h"

void printVector(Vector v);
Vector test();

int main(void)
{
    S s;
    Vector vector;
    Vector v(1, 2, 3, 4);
    int i(-9);

    //vector.Length();
    vector.Normalize();


    /*vector.Length();
    cout << "Length " << vector.length << endl;*/
    //Vector vec;
    //vector.x = -1;
    //vector.y = 0;
    //vector.z = 0;
    //vec.x = 9;
    //vec.y = 10;
    //vec.z = 11;

    //vector.Print();
    //vec.Print();
    //printVector(vector);
    //Vector v;
    //v = test();
    //v.Print();
    //vec = vector; // shallow copy -- works for struct and objects, not arrays

    return 0;
}

void printVector(Vector v) {  // NOT a member function
    std::cout << "x: " << v.x << " y: " << v.y << " z: " << v.z << std::endl; // must use the dot notation
}

Vector test() {
    Vector v;
    v.z = 100;
    return v;
}

