#include "stdafx.h"
#include "Aircraft.h"
#include <time.h>
#include "Player.h"
int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL));
	Player player;
	for (int i = 0; i < player.m_Ships.size(); i++)
	{
		player.SetupShips(player.m_Ships[i]);
	}

	player.PrintMap();
	
	return 0;
}

