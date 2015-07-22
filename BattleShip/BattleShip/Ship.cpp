#include "stdafx.h"
#include "Ship.h"


Ship::Ship()
{
}



Ship::~Ship()
{
}



HitResult Ship::HitCheck(char x, char y)
{
	return HitCheck(Point(x, y));
}

HitResult Ship::HitCheck(Point pos)
{
	for (auto& shipPos : m_Pos)
	{
		if (shipPos.x == pos.x && shipPos.y == pos.y)
		{
			m_Hp--;
			if (m_Hp <= 0)
				return DESTROY;

			return HIT;
		}

	}

	return MISS;
}

void Ship::AddPosition(Point pos)
{
	
	if (!((pos.x >= 'a') && (pos.x <= 'h') && (pos.y) >= '1' && (pos.y <= '8'))){
		printf("wrong pos\n");
		return;
	}

	if (m_Pos.size() >= m_Hp){
		printf("too many!\n");
		return;
	}

	m_Pos.push_back(pos);

}

void Ship::printPosition()
{
	for (auto& pos : m_Pos)
	{
		printf("Point: (%c, %c)\n", pos.x, pos.y);
	}
}