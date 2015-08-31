#include "stdafx.h"
#include "Aircraft.h"


void Aircraft::Reset()
{
	Ship::Reset();
	m_Hp = 5;
}

Aircraft::Aircraft()
{
	alive = true;
	m_Name = "Aircraft";
	m_Hp = 5;
	ship_Size = 5;
	ship_Type = AIRCRAFT;
}


Aircraft::~Aircraft()
{


}