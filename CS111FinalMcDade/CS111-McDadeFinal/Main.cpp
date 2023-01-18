// CS111-McDadeFinal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ExamScore.h"
int main(void)
{
	ExamScore *rPtr = new ExamScore(15.5,"Test");
	ExamScore r;
	r.setName("Summer");
	r.setScore(0.1);
	std::cout << "Pointer Values Name " << rPtr -> getName() <<" Score " <<rPtr -> getScore() << std::endl;
	std::cout << "Instance Values Name " << r.getName() << " Score " << r.getScore() << std::endl;
	std::cout << "Total " << r.getScore() + rPtr->getScore() << std::endl;
	delete rPtr;
	rPtr = &r;
	rPtr->setScore(100);
	std::cout << "Revised Value " << rPtr->getScore() << std::endl;

	return 0;
}


