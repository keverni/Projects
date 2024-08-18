#pragma once

#include <string>

class Product
{
public:
	Product();
	Product(const std::string& name, double price);

	std::string GetName() const;
	double GetPrice() const;

	bool IsValid() const;
	bool operator==(const Product& other) const;

private:
	std::string m_Name;
	double m_Price;
};
