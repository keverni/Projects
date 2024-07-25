#pragma once

#include "Animals.h"

class Cat: public Animal
{
public:
	Cat();
	virtual ~Cat();

	virtual void Voice();
};

