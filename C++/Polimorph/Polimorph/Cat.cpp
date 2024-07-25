#include "Cat.h"
#include <iostream>

Cat::Cat() :
	Animal(AnimalID::Cat)
{
}

Cat::~Cat()
{
}

void Cat::Voice()
{
	std::cout << "meow\n";
}
