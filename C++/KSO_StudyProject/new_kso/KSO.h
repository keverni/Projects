#pragma once

#include "ProductData.h"

#include <list>

class KSO
{
public:
	KSO();

public:
	void AddProduct(const std::string& NameProduct);
	void RemoveProduct(const std::string& NameProduct);
	std::list<Product> GetCart() const;
	double GetPrice() const;

private:
	Database			 m_AllProduct;
	std::list<Product>   m_ProductCart;
	double				 m_TotalPrice;
};
