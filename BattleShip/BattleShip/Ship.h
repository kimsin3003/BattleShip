#pragma once
#include <vector>

struct Point
{
	Point(){}

	Point(char ax, char ay)
	{
		x = ax; 
		y = ay;
	}
	char x, y; //x: 'a'~'h', y: '1'~'8'

};

enum HitResult
{
	MISS,
	HIT,
	DESTROY
};

class Ship
{

public:
	Ship();
	~Ship();

	HitResult HitCheck(char x, char y);
	HitResult HitCheck(Point pos);
	void AddPosition(Point pos);
	void printPosition();
	Point GetPosition(int index);

	int GetHP(){ return m_Hp; }
	std::string GetName(){ return m_Name; }


protected:
	std::string m_Name; 
	std::vector<Point> m_Pos;
	int m_Hp;
};