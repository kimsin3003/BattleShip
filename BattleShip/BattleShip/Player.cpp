
#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <string>
#include "Player.h"
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"

void Player::SetupShips(Ship* ship)
{
	Point start;
	Point temp;
	int dir;
	
	do{
		start.x = rand() % 8 + 'a';
		start.y = rand() % 8 + '1';

		dir = rand() % 4;

		if (IsValid(start, ship->GetHP(), dir)) {
			std::cout << ship->GetName() << " 배치 완료" << std::endl;
			for (int i = 0; i < ship->GetHP(); i++) {
				temp = MakePointDirected(start, dir, i);
				ship->AddPosition(temp);
				printf("%d %d \n", temp.x - 'a', temp.y - '1' );
				m_Map[temp.y - '1'][temp.x - 'a'] = 1;
				std::cout << i << "번째:" << ship->GetPosition(i).x << ship->GetPosition(i).y << "\n" << std::endl;
			}
			return;
		}
			
	} while (true);
	
}

//사용할수있는점인지 검사.
bool Player::IsValid(Point startPoint, int lenth, int dir)
{
	//시작점 범위 체크
	if (!IsValidRange(Point(startPoint.x, startPoint.y)))
		return false;

	//마지막점 범위 체크
	if (!IsValidRange(MakePointDirected(startPoint, dir, lenth)))
		return false;

	//놓을 범위 내에 다른 배가 있는지 체크.
	for (int i = 0; i < lenth; i++)
	{
		if (!IsValidPoint(MakePointDirected(startPoint, dir, i)))
			return false;
	}

	return true;
}

//범위안에 있는 점인지 검사
bool Player::IsValidRange(Point point)
{
		if (point.x < 'a' || point.x > 'h')
			return false;

		if (point.y < '1' || point.y > '8')
			return false;

		return true;
}

//다른 배가 있는 점인지 검사
bool Player::IsValidPoint(Point point)
{
	if (m_Map[point.y - '1'][point.x - 'a'] == 1)
		return false;
	return true;
}

Point Player::MakePointDirected(Point start, int dir, int i) {
	switch (dir)
	{
	case UP:
		return Point(start.x, start.y + i);
	case RIGHT:
		return Point(start.x + i, start.y);
	case DOWN:
		return Point(start.x, start.y - i);
	case LEFT:
		return Point(start.x - i, start.y);
	}
}

void Player::PrintMap()
{
	for (int i = 0; i < 8; ++i)
	{
		printf("\n");
		for (int j = 0; j < 8; ++j)
		{
			printf("%d", m_Map[i][j]);
		}
		printf("\n");
	}
}

Player::Player()
{
	m_Ships.push_back(new Aircraft());
	m_Ships.push_back(new Battleship());
	m_Ships.push_back(new Cruiser());
	m_Ships.push_back(new Destroyer());
	m_Ships.push_back(new Destroyer());

	ZeroMemory(m_Map, sizeof(m_Map));
}


Player::~Player()
{
}
