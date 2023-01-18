#pragma once
#include <iostream>
#include <fstream>
#include <string>
const int MAX = 10;

struct BoatStruct {
    std::string boatOwnerName;
    std::string boatName;
    double boatSize;
    BoatStruct();
    BoatStruct(std::string oName, std::string bName, double size);
    void print();
};

typedef BoatStruct BoatArray[MAX];
