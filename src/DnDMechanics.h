//DnDMechanics.h
#include <chrono>
int die(int die_type) 
{
	srand(time(NULL));
	return (rand() % (die_type - 1)) + 1;
}