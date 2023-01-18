#include "Point.h"

Point::Point() {
	coordinates[xCoord] = 0;
	coordinates[yCoord] = 0;
	next = NULL;
}
Point::Point(float _x, float _y) {
	coordinates[xCoord] = _x;
	coordinates[yCoord] = _y;
	next = NULL;
}

void Point::setX(float _x) {
	//x = _x;
	coordinates[xCoord] = _x;
}

float Point::getX() {
	return coordinates[xCoord];
}

void Point::setY(float _y) {
	coordinates[yCoord] = _y;
}

float Point::getY() {
	return coordinates[yCoord];
}

void Point::setNext(Point*& ptr) {
	next = ptr;
}
Point* Point::getNext() {
	return next;
}

void Point::print() {
	std::cout << "X" << coordinates[xCoord] << " Y " << coordinates[yCoord] << std::endl;
}
float Point::distance(Point p) {

}
bool Point::equal(Point p) {

}
void Point::translation(float distance) {

}
void Point::rotate(float rotateAmount) {

}
void Point::scale(float x, float y) {

}