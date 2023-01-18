#pragma once


#define S_hpp
#include <iostream>


struct S {
    float f;
    S* next;
    S();
    S(float _f);
    void print();
};

typedef S* SPtr;

