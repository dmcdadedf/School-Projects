#include "Vector.h"

Vector :: Vector() {
    x = 0;
    y = 0;
    z = 0;
    length = 0;
}

Vector :: Vector(float _x, float _y, float _z, float _length) {
    x = _x;
    y = _y;
    z = _z; 
    length = _length; 
}

void Vector :: Print() {
    std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;  // direct access to the member variables
}

void Vector :: Length() {  // the length of the vector defined by Pythagorian Theorem
    float t = pow(x, 2) + pow(y, 2) + pow(z, 2);
    length = sqrt(t);
}

void Vector :: Normalize() {  // calculates pure direction
    Length();
    float sum = x + y + z;
    if (sum != 0) {
        x = x / length;
        y = y / length;
        z = z / length;
    }
    else {
        std::cout << "Error can't normalize a zero vector" << endl;
    }


}
