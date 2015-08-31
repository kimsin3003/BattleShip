#include "stdafx.h"
#include <iostream>
#include "Ship.h"




//가지고 있는 점인지 검사
bool Ship::HasPoint(Point point)
{

	for (auto myPoint : m_points) {
		if (myPoint.x == point.x && myPoint.y == point.y)
			return true;
	}

	return false;
}

void Ship::AddPoint(Point point)
{
	
	if (!((point.x >= 'a') && (point.x <= 'h') && (point.y) >= '1' && (point.y <= '8'))){
		printf("wrong point\n");
		return;
	}

	if (m_points.size() >= (size_t)ship_Size){
		printf("too many!\n");
		return;
	}
	m_points.push_back(point);

}

void Ship::PrintPoint()
{
	for (auto& point : m_points)
	{
		printf("Point: (%c, %c)\n", point.x, point.y);
	}
}

void Ship::RemovePoint(Point point ) { 
	for (auto iter = m_points.begin(); iter != m_points.end(); iter++) {
		if (iter->x == point.x && iter->y == point.y) {
			m_points.erase(iter);
			m_Hp--;
			return;
		}
	}
	
}

void Ship::Reset()
{
	alive = true;
	m_points.clear();
}

Ship::Ship()
{
}



Ship::~Ship()
{
}
