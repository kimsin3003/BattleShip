#pragma once
#include "Player.h"
class GameManager
{
public:
	static GameManager* GetInstance();
	void Play();
	void PrintHitSign(HitResult hitsign);
	HitResult PlayTern(Player* attacker, Player* defender);

private:
	static GameManager* gameManager;
	GameManager();
	~GameManager();


};
