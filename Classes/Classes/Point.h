#pragma once
#include <iostream>
#include <stdio.h>
#include <cmath>

enum coordinate {xCoord,yCoord}; 

class Point {
	private:
		Point* next;  // pointer to next point
protected:
	float coordinates[2];
		/*float x = coordinates[0];
		float _x = coordinates[xCoord];*/
		/*float x;
		float y;*/

public:
	// Setters and Getters
	Point();
	Point(float _x, float _y);
	void setX(float _x);
	float getX();
	void setY(float _y);
	float getY();
	void setNext(Point* &ptr);
	Point* getNext();



	// Support Functions
	void print();
	float distance(Point p);
	bool equal(Point p);
	void translation(float distance);
	void rotate(float rotateAmount);
	void scale(float x, float y);

	virtual void example();

	//Friend
	friend bool equal(Point p1, Point p2);
	//Opperator
	

};

typedef Point* PointPtr;