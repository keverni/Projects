#pragma once
#include "ProductCart.h"

class KSO
{

public:
	KSO();

	bool AddProduct(std::string NameProduct);
	bool RemoveProduct(std::string NameProduct);
	std::list<Product> GetCart();
	int GetPrice();

private:
	std::list<Product> m_AllProduct;
	ProductCart			 m_ProductCart;
	double				 m_TotalPrice;
};