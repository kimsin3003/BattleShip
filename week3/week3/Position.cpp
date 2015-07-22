#include "stdafx.h"
#include "Position.h"
#include <iostream>

Position::Position()
{

	ships = { "Aircraft", "Battleship", "Cruiser", "Destroyer", "Destroyer" };


}


Position::~Position()
{

}

void Position::setInput(std::string input)
{
	mInput = input;
}

std::string Position::getInput()
{
	return mInput;
}

bool Position::isValid()
{
	if (mInput[0] < 'A' || mInput[0] > 'H')
		return false;
	if (mInput[1] < '1' || mInput[1] > '8')
		return false;

	return true;
}

std::string Position::checkHit()
{

}