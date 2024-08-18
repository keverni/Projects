#pragma once

#include "Product.h"
#include <unordered_map>

class Database
{
public:
	void AddProduct(const Product& product);
	void EditProduct(const Product& product);

	void RemoveProduct(const std::string& name);
	Product GetProduct(const std::string& name);

private:
	size_t Hash(const std::string& name);

private:
	std::unordered_map<size_t, Product> m_Products;

};
