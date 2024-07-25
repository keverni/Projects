#pragma once
#include "Worker.h"

class Medic: public Worker
{
public:
	Medic(double k);
	virtual ~Medic();

	virtual void payment(int hours);
};

