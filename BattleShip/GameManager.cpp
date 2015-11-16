#include "stdafx.h"
#include "GameManager.h"

GameManager* GameManager::gameManager = nullptr;

GameManager* GameManager::GetInstance()
{
	if (!gameManager)
		gameManager = new GameManager();
	return gameManager;
}

void GameManager::Play()
{
	
	int count = 1;
	int sum = 0;

	std::vector<Player*> players;
	players.push_back(new Computer());
	players.push_back(new Human());

	while (count <= 10) {

		Player* attacker;
		Player* defender;
		HitResult hit;
		int ternNum = 0;
		

		for (auto player : players)
			player->Reset();
		
		std::cout << count << "st Game Start" << std::endl;

		while(true){
			attacker = players.at(ternNum % players.size());
			defender = players.at((ternNum + 1) % players.size());
			hit = PlayTern(attacker, defender);

			//PrintHitSign(hit);

			if (!defender->IsAlive()) {
				std::cout << "Player" << ternNum % players.size() + 1 << " Win!" << std::endl;
				for (auto iter = defender->attackedPoints.begin(); iter != defender->attackedPoints.end(); iter++)
					std::cout << iter->x << " " << iter->y << std::endl;
				break;
				getchar();
			}

			ternNum++;
		}
		
		count++;
		sum += ternNum / 2;
	}

	std::cout << "Average Tern Count: " << sum / 10 << std::endl;
	getchar();

}

HitResult GameManager::PlayTern(Player* attacker, Player* defender)
{
	
	Point attackPoint;
	HitResult result;
	attackPoint = attacker->Attack();
	result = defender->HitCheck(attackPoint);
	attacker->UpdateStrategy(result);

	return result;
}

void GameManager::PrintHitSign(HitResult hitSign)
{
	switch (hitSign)
	{
	case MISS:
		printf("Miss\n\n");
		break;
	case HIT:
		printf("Hit\n\n");
		break;
	case DESTROYER_DESTROYED:
		printf("Distroyer destroyed\n\n");
		break;
	case CRUISER_DESTROYED:
		printf("Cruiser destroyed\n\n");
		break;
	case BATTLESHIP_DESTROYED:
		printf("Battleship destroyed\n\n");
		break;
	case AIRCRAFT_DESTROYED:
		printf("Aircraft destroyed\n\n");
		break;	
	}
}

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}
