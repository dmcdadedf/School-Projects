#pragma once
#include <string>

class ExamScore {
private:
	float score;
	std::string name;
public:
	ExamScore();
	ExamScore(float _a, std::string _b);
	void setScore(float a);
	float getScore();
	void setName(std::string b);
	std::string getName();

};