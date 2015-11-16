#include "stdafx.h"
#include "Human.h"

Point Human::Attack()
{
	char x;
	char y;
	do {
		x = rand() % MAP_WIDTH;
		y = rand() % MAP_WIDTH;
	} while (!IsValidAttack(Point(x, y)));

	attackedPoints.push_back(Point(x, y));

	return Point(x, y);
}

void Human::UpdateStrategy(HitResult hitResult)
{
}

Human::Human()
{
}


Human::~Human()
{
}
