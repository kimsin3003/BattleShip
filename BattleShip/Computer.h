#pragma once
#include "Player.h"
class Computer :
	public Player
{
public:
	Point Attack() override;
	void UpdateStrategy(HitResult hitResult) override;
	void Reset();
	Computer();
	~Computer();

private:
	int ComputeInterval();
	void PrintMap();
	void SetEnemyShips(HitResult hitResult);
	bool huntingMode;
	Point* nextPoint;
	std::vector<Point> checkedPoints;
	Point lastAttackPoint;
	int strategicInterval;
	std::vector<Ship_Type> enemyShips;
};

