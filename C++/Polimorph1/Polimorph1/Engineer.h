#pragma once
#include "Worker.h"

class Engineer: public Worker
{
public:
	Engineer(double k);
	virtual ~Engineer();

	virtual void payment(int hours);
};

