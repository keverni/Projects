#include "KSO.h"


void KSO::AddProduct(const std::string& NameProduct)
{
	auto Find_Product = m_AllProduct.GetProduct(NameProduct);
	m_ProductCart.push_back(Find_Product);
	m_TotalPrice += Find_Product.m_Price;
}

void KSO::RemoveProduct(const std::string& NameProduct)
{
	auto Find_Product = m_AllProduct.GetProduct(NameProduct);
	m_ProductCart.remove(Find_Product);
	m_TotalPrice -= Find_Product.m_Price;
}

std::list<Product> KSO::GetCart() const
{
	return m_ProductCart;
}

double KSO::GetPrice() const
{
	return m_TotalPrice;
}

