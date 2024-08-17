#include "Product.h"

Product::Product(const std::string& name, int price) :
	m_Name(name),
	m_Price(price),
	m_Product_id(std::hash<std::string>{}(name))
{
}

bool Product::operator==(const Product& other) const
{
	return this->m_Product_id == other.m_Product_id;
}


