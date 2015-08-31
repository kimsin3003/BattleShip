#pragma once
#include "Ship.h"

#include "string"
#include <iostream>

class Player
{
public:
	
	Player();
	~Player();
	void SetupShips();
	bool IsValidPoint(Point startPoint, int lenth, int dir);
	bool IsValidRange(Point point);
	Point MakePointDirected(Point start, int dir, int i);
	bool IsAlive();
	Point Attack();
	//Map GetMap() { return map; };
	Ship* GetShip(int i) { return m_Ships.at(i); };
	int GetShipNum() { return m_Ships.size(); }
	HitResult HitCheck(Point point);

	void Reset();
	void Init();

private:
	
	std::vector<Ship*> m_Ships;
	HitResult DestoySign(Ship* ship);
	std::vector<Point> attackedPoints;
	bool IsValidAttack(Point point);
};

