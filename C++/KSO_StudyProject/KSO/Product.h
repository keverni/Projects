#pragma once
#include <string>

struct Product
{

public:
	Product(std::string name, int price, double weight = 0);

public:
	std::string m_Name;
	int			m_Price;

	double		m_Weight;
};

