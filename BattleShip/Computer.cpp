#include "stdafx.h"
#include "Computer.h"


Point Computer::Attack()
{
	
	Point attackPoint;
	do {

		//basic routine -> complete
		if (!huntingMode) {

			attackPoint = lastAttackPoint;

			//initial status 
			if (lastAttackPoint.x == -1 && lastAttackPoint.y == -1) {
				attackPoint = Point(0, 0);
			}
			else if (!IsValidRange(Point(attackPoint.x + 1 , attackPoint.y - 1))) {

				attackPoint.x = lastAttackPoint.y;
				attackPoint.y = lastAttackPoint.x;

				if (attackPoint.x == 0) {
					attackPoint.y += strategicInterval;
					while (attackPoint.y > 7) {
						attackPoint.x++;
						attackPoint.y--;
					}
				}

				else// -> attackPoint.y == 7
					attackPoint.x += strategicInterval;

				if (attackPoint.x > 7 || attackPoint.y > 7) {
					std::cout << "No More Ship" << std::endl;
					return attackPoint;
				}

			}

			else {
				attackPoint.x++;
				attackPoint.y--;
			}
			
			lastAttackPoint = attackPoint;
		}

		//investigation routine
		else {
			//lastAttackPoint�� �״�� �д�. -> �踦 �ı��� �� �ٽ� ���ƿͼ� ���� ������ ��Ǯ���ϱ�����.
			
			attackPoint = *nextPoint;
			delete nextPoint;
			//printf("Final: %d %d\n", attackPoint.x, attackPoint.y);
		}
	} while (!IsValidAttack(attackPoint));
	//printf("attack: %d, %d", attackPoint.x, attackPoint.y);
	attackedPoints.push_back(attackPoint);

	return attackPoint;
}

void Computer::UpdateStrategy(HitResult hitResult)
{
	static int dir = -1;
	static int count = 0;

	
	if (hitResult == MISS) {
		return;
	}
	if (hitResult == HIT) {
		//printf("Hit\n");
		//�������� �ϳ� �ɷ����� -> �ֺ� Ž���غ���.
		huntingMode = true;
		if (dir == -1 && nextPoint == nullptr) {
			
			if (IsValidRange(MakePointDirected(lastAttackPoint, DIR_RIGHT, 1)))
				checkedPoints.push_back(MakePointDirected(lastAttackPoint, DIR_RIGHT, 1));
			if (IsValidRange(MakePointDirected(lastAttackPoint, DIR_DOWN, 1)))
				checkedPoints.push_back(MakePointDirected(lastAttackPoint, DIR_DOWN, 1));
			if (IsValidRange(MakePointDirected(lastAttackPoint, DIR_LEFT, 1)))
				checkedPoints.push_back(MakePointDirected(lastAttackPoint, DIR_LEFT, 1));
			if (IsValidRange(MakePointDirected(lastAttackPoint, DIR_UP, 1)))
				checkedPoints.push_back(MakePointDirected(lastAttackPoint, DIR_UP, 1));

			checkedPoints.push_back(MakePointDirected(lastAttackPoint, DIR_MAX, 1));//���� ����� 0���� ������ �ʱ� ���� ���� ����Ʈ
			return;
		}

		//Ž���ؼ� ������ �˾����� ���� ����.
		else if (dir == -1) {
			//printf("Points To Check1 %d", pointsToCheck.size());
			//getchar();
			dir = DIR_MAX - checkedPoints.size() - 1;
			checkedPoints.clear();
		}

		//������ �������� ���� ��ġ�� �����Ѵ�.
		//printf("Points To Check2 %d", pointsToCheck.size());
		//getchar();
		count++;
		checkedPoints.push_back(MakePointDirected(lastAttackPoint, (DIR)dir, count));
		return;
	}

	else {
		switch (hitResult)
		{
		case DESTROYER_DESTROYED:
			printf("Distroyer destroyed\n\n");
			break;
		case CRUISER_DESTROYED:
			printf("Cruiser destroyed\n\n");
			break;
		case BATTLESHIP_DESTROYED:
			printf("Battleship destroyed\n\n");
			break;
		case AIRCRAFT_DESTROYED:
			printf("Aircraft destroyed\n\n");
			break;
		}
		getchar();
		dir = -1;
		count = 0;
		checkedPoints.clear();
		SetEnemyShips(hitResult);
		strategicInterval = ComputeInterval();
	}

}

//���� ���� ũ���� ���� ũ�⸦ ���ϰ� �׺��� 1ū ���� Interval�� ����.
int Computer::ComputeInterval()
{
	int newInterval = AIRCRAFT;

	for (int i = 0; i < enemyShips.size(); i++) {
		if (newInterval > enemyShips.at(i))
			newInterval = enemyShips.at(i);
	}

	return newInterval + 1;
}

void Computer::PrintMap() {
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			for (auto& point : attackedPoints) {
				if(point.x == j && point.y ==i)
					std::cout << "A" << std::endl;
			}
		}
		std::cout << "\n" << std::endl;
	}
}

void Computer::SetEnemyShips(HitResult hitResult) {

	
	switch (hitResult)
	{
	case DESTROYER_DESTROYED:
		for (auto iter = enemyShips.begin(); iter != enemyShips.end(); iter++) {
			if (*iter == DESTROYER) {
				enemyShips.erase(iter);
				break;
			}
		}
		break;
	case CRUISER_DESTROYED:
		for (auto iter = enemyShips.begin(); iter != enemyShips.end(); iter++) {
			if (*iter == CRUISER) {
				enemyShips.erase(iter);
				break;
			}
		}
		break;
	case BATTLESHIP_DESTROYED:
		for (auto iter = enemyShips.begin(); iter != enemyShips.end(); iter++) {
			if (*iter == BATTLESHIP) {
				enemyShips.erase(iter);
				break;
			}
		}
		break;
	case AIRCRAFT_DESTROYED:
		for (auto iter = enemyShips.begin(); iter != enemyShips.end(); iter++) {
			if (*iter == AIRCRAFT) {
				enemyShips.erase(iter);
				break;
			}
		}
		break;
	}

}

void Computer::Reset() {

	Player::Reset();
	nextPoint = nullptr;
	lastAttackPoint = Point(-1, -1);
	strategicInterval = 2;
	enemyShips.clear();
	enemyShips.push_back(DESTROYER);
	enemyShips.push_back(DESTROYER);
	enemyShips.push_back(CRUISER);
	enemyShips.push_back(AIRCRAFT);
}

Computer::Computer()
{
}


Computer::~Computer()
{
}
