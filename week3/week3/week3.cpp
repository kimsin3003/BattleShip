// week3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Position.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	Position p = Position();

	while (true) {
		std::string input;
		std::cin >> input;
		p.setInput(input);
		if (p.isValid()) break;
		std::cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << std::endl;
	};
	std::cout << p.getInput();

	

	getchar();
	getchar();
	return 0;
}

