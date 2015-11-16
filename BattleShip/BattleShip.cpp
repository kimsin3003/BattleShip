#include "stdafx.h"
#include "Battleship.h"


void Battleship::Reset()
{
	Ship::Reset();
	m_Hp = 4;
}
Battleship::Battleship()
{
	alive = true;
	m_Name = "Battleship";
	m_Hp = 4;
	ship_Size = 4;
	ship_Type = BATTLESHIP;
}


Battleship::~Battleship()
{
}
