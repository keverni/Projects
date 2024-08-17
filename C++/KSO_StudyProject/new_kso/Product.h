#pragma once

#include <string>

struct Product
{

public:
	Product(const std::string& name, int price);
	bool operator==(const Product& other) const;

public:
	std::string m_Name;
	int			m_Price;

	size_t		m_Product_id;
};

