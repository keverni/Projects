#pragma once
#include <list>
#include "Product.h"
#include <iostream>
#include <algorithm>

class ProductCart
{

public:
	void AddProduct(const Product& product);
	bool RemoveProduct(const Product& product);
	std::list<Product> GetCart();

private:
	std::list<Product> m_ListOfProduct;
};

