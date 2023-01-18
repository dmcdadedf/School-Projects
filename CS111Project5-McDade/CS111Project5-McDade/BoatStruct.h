#pragma once
#include <iostream>
#include <fstream>
#include <string>
#define S_hpp

struct BoatStruct {
    std::string boatOwnerName;
    std::string boatName;
    double boatSize;
    BoatStruct* next; //ALL constructors must set this to NULL
    BoatStruct();
    BoatStruct(std::string oName, std::string boatName, double size);
    void print();
};

typedef BoatStruct* BoatStructPtr;

