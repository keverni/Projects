#pragma once
#include <vector>
#include "Product.h"
#include <iostream>
#include <algorithm>

class ProductCart
{

public:
	void AddProduct(const Product& product);
	bool RemoveProduct(const Product& product);
	std::vector<Product> GetCart();

private:
	std::vector<Product> m_ListOfProduct;
};

