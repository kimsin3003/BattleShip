#pragma once
#include "Ship.h"

#include "string"
#include <iostream>

enum PlayerType {
	HUM,
	COM
};

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

	virtual Point Attack() = 0;
	virtual void UpdateStrategy(HitResult hitResult) = 0;

	HitResult HitCheck(Point point);

	Ship* GetShip(int i) { return m_Ships.at(i); };
	int GetShipNum() { return m_Ships.size(); }


	virtual void Reset();
	std::vector<Point> attackedPoints;

protected:
	std::vector<Ship*> m_Ships;
	HitResult DestoySign(Ship* ship);
	bool IsValidAttack(Point point);
};

