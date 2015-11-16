#include "stdafx.h"
#include "Destroyer.h"

void Destroyer::Reset()
{
	Ship::Reset();
	m_Hp = 2;
}

Destroyer::Destroyer()
{
	alive = true;
	m_Name = "Destroyer";
	m_Hp = 2;
	ship_Size = 2;
	ship_Type = DESTROYER;
}


Destroyer::~Destroyer()
{
}
