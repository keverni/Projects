#include <iostream>
#include <string>
#include "Animals.h"
#include "Bird.h"
#include "Cat.h"

void PrintID(AnimalID id)
{
	if (id == AnimalID::Bird)
	{
		std::cout << "Bird\n";
	}
	else if (id == AnimalID::Cat)
	{
		std::cout << "Cat\n";
	}
}

void Voice(Animal& animal)
{
	animal.Voice();
}


int main()
{

	Cat cat;
	Bird bird;

	Voice(bird);
	PrintID(bird.GetID());

	Voice(cat);
	PrintID(cat.GetID());

	return 0;
}