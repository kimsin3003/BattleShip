// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


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

	Point(char ax, char ay)
	{
		x = ax;
		y = ay;
	}
	char x, y; //x: 'a'~'h', y: '1'~'8'
};

