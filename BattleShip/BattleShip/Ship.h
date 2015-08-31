#pragma once
#include <vector>


enum Ship_Type {
	EMPTY = 0,
	DESTROYER = 2,
	CRUISER,
	BATTLESHIP,
	AIRCRAFT
};

enum HitResult
{
	MISS,
	HIT,
	AIRCRAFT_DESTROYED,
	BATTLESHIP_DESTROYED,
	CRUISER_DESTROYED,
	DESTROYER_DESTROYED
};

class Ship
{

public:
	Ship();
	~Ship();

	void SetPosition();
	void PrintPoint();
	Point Getpoint(int index) { return m_points[index]; }
	void RemovePoint(Point point);
	bool HasPoint(Point point);
	int GetHP() { return m_Hp; }
	int GetShipSize() { return  ship_Size; }
	std::string GetName(){ return m_Name; }
	Ship_Type GetShipType() { return ship_Type; }
	bool IsAlive() { return alive; }
	virtual void Reset();
	void AddPoint(Point point);
	//virtual	HitResult DistroySign() = 0;


protected:
	std::string m_Name; 
	std::vector<Point> m_points;
	int m_Hp;
	int ship_Size;
	Ship_Type ship_Type;
	bool alive;
};