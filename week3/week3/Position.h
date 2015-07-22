#include "string"
#include <vector>

#pragma once
class Position
{
public:
	Position();
	~Position();
	bool isValid();
	void setInput(std::string input);
	std::string getInput();
	std::string checkHit();

private:
	std::string mInput;
	std::vector<std::string> ships;
};

