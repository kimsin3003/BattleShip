#pragma once
#include <vector>

class Ship
{

public:
	typedef struct position{
		int x;
		int y;
	}POS;

protected:
	
	std::vector<POS> body;
	std::string name;

public:
	Ship();
	~Ship();
	void isAlive();
	void getName();
	
};

