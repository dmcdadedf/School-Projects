#include "Character.h"

Character::Character() {
	health = 0;
}
Character::Character(float x, float y) {
	coordinates[xCoord] = x;
	coordinates[yCoord] = y;
	health = 0;
}
void Character::takeDamage(int damage) {
	health -= damage;
}
int Character::getHealth() {
	return health;
}

void Character::print() {
	std::cout << "Health " << health;
	Point::print();
}