#include "ExamScore.h"

ExamScore::ExamScore() {
	score = 0;
	name = "";
}
ExamScore::ExamScore(float _a, std::string _b) {
	score = _a;
	name = _b;
}
void ExamScore::setScore(float a) {
	score = a;
}
float ExamScore::getScore() {
	return score;
}
void ExamScore::setName(std::string b) {
	name = b;
}
std::string ExamScore::getName() {
	return name;
}