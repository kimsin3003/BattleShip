#pragma once
#include "Ship.h"
class Destroyer :
	public Ship
{
public:
	Destroyer();
	~Destroyer();
	void Reset() override;
};
