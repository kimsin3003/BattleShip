#include "stdafx.h"
#include <iostream>
#include <string>
#include "Player.h"
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"


void Player::SetupShips()
{

	for (auto ship : m_Ships) {

		
		
		
		Point start;
		Point temp;
		int dir;
		
		do {
			start.x = rand() % MAP_WIDTH;
			start.y = rand() % MAP_WIDTH;
				
			dir = rand() % DIR_MAX;

			if (IsValidPoint(start, ship->GetShipSize(), dir)) {
				std::cout << ship->GetName() << " ��ġ �Ϸ�" << std::endl;
				for (int i = 0; i < ship->GetShipSize(); i++) {
					temp = MakePointDirected(start, dir, i);
					ship->AddPoint(temp);
					printf("%d %d \n", temp.x, temp.y);
					std::cout << i << "��°:" << ship->Getpoint(
						
						i).x << ship->Getpoint(i).y << "\n" << std::endl;
				}
				break;
			}

		} while (true);
	}

}


//����Ҽ��ִ������� �˻�.
bool Player::IsValidPoint(Point startPoint, int lenth, int dir)
{
	//������ ���� üũ
	if (!IsValidRange(Point(startPoint.x, startPoint.y)))
		return false;

	//�������� ���� üũ
	if (!IsValidRange(MakePointDirected(startPoint, dir, lenth)))
		return false;

	//���� ���� ���� �ٸ� �谡 �ִ��� üũ.
	for (auto ship : m_Ships) {
		for (int i = 0; i < lenth; i++)
		{
			if (ship->HasPoint(MakePointDirected(startPoint, dir, i)))
				return false;
		}
	}

	return true;
}

//�����ȿ� �ִ� ������ �˻�
bool Player::IsValidRange(Point point)
{
	if (point.x < 0 || point.x > 7)
		return false;


	if (point.y < 0 || point.y > 7)
		return false;

	//printf("%d %d True\n", point.x, point.y);
	return true;
}

Point Player::MakePointDirected(Point start, int dir, int i) {
	switch (dir)
	{
	case DIR_UP:
		return Point(start.x, start.y + i);
	case DIR_RIGHT:
		return Point(start.x + i, start.y);
	case DIR_DOWN:
		return Point(start.x, start.y - i);
	case DIR_LEFT:
		return Point(start.x - i, start.y);
	}

	//std::cout << "DIRECTION OUT OF RANGE" << std::endl;
	return Point(-1, -1);
}

bool Player::IsAlive() {
	for (auto ship : m_Ships)
	{
		if (ship->GetHP() > 0)
			return true;
	}
	return false;
}


bool Player::IsValidAttack(Point point) {
	for (auto& p : attackedPoints) {
		if (p.x == point.x && p.y == point.y)
			return false;
	}
	return true;
}

HitResult Player::HitCheck(Point point)
{
	Ship* attackedShip = nullptr;

	for (auto& ship : m_Ships) {
		if (ship->HasPoint(point))
			attackedShip = ship;
	}

	if (attackedShip != nullptr) {
		//���ݴ��� ���� �����.
		attackedShip->RemovePoint(point);

		//hp�� 0�̶�� ������ ��������.
		if (attackedShip->GetHP() == 0)
			return DestoySign(attackedShip);

		return HIT;
	}
	return MISS;
}


HitResult Player::DestoySign(Ship* ship) {
	switch (ship->GetShipType())
	{
	case DESTROYER:
		return DESTROYER_DESTROYED;
	case CRUISER:
		return CRUISER_DESTROYED;
	case BATTLESHIP:
		return BATTLESHIP_DESTROYED;
	case AIRCRAFT:
		return AIRCRAFT_DESTROYED;
	}
	return HIT;
}

void Player::Reset() {
	for (auto ship : m_Ships) {
		ship->Reset();
	}
	SetupShips();
	attackedPoints.clear();
}


Player::Player()
{
	m_Ships.push_back(new Aircraft());
	m_Ships.push_back(new Battleship());
	m_Ships.push_back(new Cruiser());
	m_Ships.push_back(new Destroyer());
	m_Ships.push_back(new Destroyer());
}


Player::~Player()
{
	for (auto iter = m_Ships.begin(); iter != m_Ships.end(); iter++)
		delete *iter;

	m_Ships.clear();
}
