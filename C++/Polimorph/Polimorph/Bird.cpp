#include "Bird.h"
#include <iostream>

Bird::Bird() :
	Animal(AnimalID::Bird)
{
}

Bird::~Bird()
{
}

void Bird::Voice()
{
	std::cout << "chirik\n";
}