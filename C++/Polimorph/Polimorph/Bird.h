#pragma once

#include "Animals.h"

class Bird: public Animal
{
public:
	Bird();
	virtual ~Bird();

	virtual void Voice();
};

