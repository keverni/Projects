#pragma once
#include <string>

struct Person
{
	std::string LastName;
	std::string FirstName;
	std::string Date;
	std::string City;
	double		Balance;

	bool IsValid() const 
	{
		return !LastName.empty() && !FirstName.empty() && !Date.empty() && !City.empty() && Balance > 0.0;
	}
};