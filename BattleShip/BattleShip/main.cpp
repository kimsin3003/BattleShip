#include "stdafx.h"
#include "Aircraft.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Aircraft aircraft;
	Point p = Point('a', '1');

	p.x = 'a';
	p.y = '1';


	printf("[Aircreaft] name = %s, hp = %d\n",
		aircraft.GetName().c_str(),
		aircraft.GetHP());


	aircraft.AddPosition(p);
	aircraft.AddPosition(Point('z','1'));
	aircraft.AddPosition(p);
	aircraft.AddPosition(Point('z', '1'));
	aircraft.AddPosition(p);
	aircraft.AddPosition(p);
	aircraft.AddPosition(p);
	aircraft.AddPosition(p);
	aircraft.printPosition();

	for (int i = 0; i < 5; ++i){
		switch (aircraft.HitCheck(p))
		{
		case MISS:
			printf("MISS\n");
			break;
		case HIT:
			printf("HIT\n");
			break;
		case DESTROY:
			printf("DESTROY");
			break;
		}
	}

	
	return 0;
}

