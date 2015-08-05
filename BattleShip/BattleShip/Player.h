#pragma once
#include "Ship.h"

enum DIR {
	UP,
	RIGHT,
	DOWN,
	LEFT
};

class Player
{
public:
	Player();
	~Player();
	void SetupShips(Ship* ship);

	void PrintMap();
	std::vector<Ship*> m_Ships;
private:
	bool IsValidRange(Point point);
	bool IsValidPoint(Point point);
	bool IsValid(Point startPoint, int lenth, int dir);
	Point MakePointDirected(Point start, int dir, int i);
protected:
	int m_Map[8][8];
	
};

