#include "stdafx.h"
#include <iostream>
#include "Ship.h"




//가지고 있는 점인지 검사
bool Ship::HasPoint
(Point point)
{

	for (auto myPoint : m_Points) {
		if (myPoint.x == point.x && myPoint.y == point.y)
			return true;
	}

	return false;
}

void Ship::AddPoint(Point point)
{
	
	if (!((point.x >= 0) && (point.x <= 7) && (point.y) >= 0 && (point.y <= 7))){
		printf("wrong point\n");
		return;
	}

	if (m_Points.size() >= (size_t)ship_Size){
		printf("too many!\n");
		return;
	}
	m_Points.push_back(point);

}

void Ship::PrintPoint()
{
	for (auto& point : m_Points)
	{
		printf("Point: (%d, %d)\n", point.x, point.y);
	}
}

void Ship::RemovePoint(Point point ) { 
	for (auto iter = m_Points.begin(); iter != m_Points.end(); iter++) {
		if (iter->x == point.x && iter->y == point.y) {
			m_Points.erase(iter);
			m_Hp--;
			return;
		}
	}
	
}

void Ship::Reset()
{
	alive = true;
	m_Points.clear();
}

Ship::Ship()
{
}



Ship::~Ship()
{
}
