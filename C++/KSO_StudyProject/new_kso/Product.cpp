#include "Product.h"

Product::Product() :
	m_Price(0.0)
{
}

Product::Product(const std::string& name, double price) :
	m_Name(name),
	m_Price(price)
{
}

bool Product::operator==(const Product& other) const
{
	return m_Name == other.m_Name;
}

std::string Product::GetName() const
{
	return m_Name;
}

double Product::GetPrice() const
{
	return m_Price;
}

bool Product::IsValid() const
{
	return !m_Name.empty() && m_Price > 0.0;
}

