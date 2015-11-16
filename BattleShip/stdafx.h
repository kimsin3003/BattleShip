// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include <iostream>
#include <stdio.h>
#include <tchar.h>
using namespace std;

enum DIR {
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_MAX
};

#define MAP_WIDTH 8

struct Point
{
	Point() {}

	Point(int ax, int ay)
	{
		x = ax;
		y = ay;
	}
	int x, y; //x: '0'~'7', y: '0'~'7'
};


enum Ship_Type {
	DESTROYER = 2,
	CRUISER,
	BATTLESHIP,
	AIRCRAFT
};

enum HitResult
{
	MISS,
	HIT,
	DESTROYER_DESTROYED,
	CRUISER_DESTROYED,
	BATTLESHIP_DESTROYED,
	AIRCRAFT_DESTROYED
};
