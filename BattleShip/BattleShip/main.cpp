#include "stdafx.h"
#include "Aircraft.h"
#include <time.h>
#include "Player.h"
#include "GameManager.h"
int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL));
	GameManager* gm = GameManager::GetInstance();
	gm->Play();
	return 0;
}

