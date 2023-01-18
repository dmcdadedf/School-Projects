// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Point.h"
#include "Character.h"
#include <iostream>

float Distance(Point p1, Point p2);

#define TRIANGLE_SIZE 3
void triagleTranslate(Point triangle[]);
void trianglePrint(Point triangle[]);

int main()
{
    Character c(9,9);
    c.print();

    Point triangle[TRIANGLE_SIZE];
    std::cout << "Triangle before translation \n";
    trianglePrint(triangle);
    std::cout << "Triangle after translation \n";
    triagleTranslate(triangle, -5);
    trianglePrint(triangle);

   /* Point p0(1, 2);
    Point p1(-1, -2);
    bool b = p0.equal(p0);

    p0.print();
    p1.print();
    
    float f = Distance(p0, p1);
    f = p0.distance(p1);*/
    return 0;
}

float Distance(Point p1, Point p2) {
    float temp = sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
    return temp;
}

void triagleTranslate(Point triangle[],float distanceToTranslate) {
    for (int i = 0; i < TRIANGLE_SIZE; i++) {
        triangle[i].translation(distanceToTranslate);
        /*triangle[i].setX(triangle[i].getX() + distanceToTranslate);
        triangle[i].setY(triangle[i].getY() + distanceToTranslate);*/
    }
}
void trianglePrint(Point triangle[]) {
    for (int i = 0; i < TRIANGLE_SIZE; i++) {
        triangle[i].print();
    }
}

// protection  -- Private(Scoped only within class) / Friend()

