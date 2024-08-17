#pragma once

#include "Product.h"

#include <list>
#include <string>

class ProductData
{
public:
	ProductData();

	const Product& GetProduct(const std::string& ProductName) const;

private:
	std::list<Product> m_Product_Data;
};

