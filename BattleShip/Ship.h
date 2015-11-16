#pragma once
#include <vector>

class Ship
{

public:
	Ship();
	~Ship();

	void PrintPoint();
	
	Point Getpoint(int index) { return m_Points[index]; }
	void RemovePoint(Point point);
	bool HasPoint(Point point);
	int GetHP() { return m_Hp; }
	int GetShipSize() { return  ship_Size; }
	std::string GetName(){ return m_Name; }
	Ship_Type GetShipType() { return ship_Type; }
	bool IsAlive() { return alive; }
	virtual void Reset();
	void AddPoint(Point point);


protected:
	std::string m_Name; 
	std::vector<Point> m_Points;
	int m_Hp;
	int ship_Size;
	Ship_Type ship_Type;
	bool alive;
};