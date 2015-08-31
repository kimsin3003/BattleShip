#include "stdafx.h"
#include "Cruiser.h"


void Cruiser::Reset()
{
	Ship::Reset();
	m_Hp = 3;
}

Cruiser::Cruiser()
{
	alive = true;
	m_Name = "Cruiser";
	m_Hp = 3;
	ship_Size = 3;
	ship_Type = CRUISER;
}


Cruiser::~Cruiser()
{
}
