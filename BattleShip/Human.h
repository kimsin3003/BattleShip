#pragma once
#include "Player.h"
class Human :
	public Player
{
public:
	Point Attack() override;
	void UpdateStrategy(HitResult hitResult) override;
	Human();
	~Human();
};

