#pragma once
#include "Ship.h"
class Aircraft :
	public Ship
{
public:
	Aircraft();
	~Aircraft();
	void Reset() override;
	
};

