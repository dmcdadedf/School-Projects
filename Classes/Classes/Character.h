#pragma once

#include <iostream>
#include "Point.h"

class Character : public Point {
private:
	int health;
public:
	Character();
	Character(float x, float y);
	void takeDamage(int damage);
	int getHealth();
	void print();


};

