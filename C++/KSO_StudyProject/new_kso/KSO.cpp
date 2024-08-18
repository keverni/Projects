#include "KSO.h"

#include <algorithm>

KSO::KSO()
{
	m_AllProduct.AddProduct({ "Juice", 10.0 });
	m_AllProduct.AddProduct({ "Chips", 120.0 });
	m_AllProduct.AddProduct({ "Bread", 35.0 });
	m_AllProduct.AddProduct({ "Milk", 89.99 });
}

void KSO::AddProduct(const std::string& NameProduct)
{
	auto Find_Product = m_AllProduct.GetProduct(NameProduct);
	m_ProductCart.push_back(Find_Product);
	m_TotalPrice += Find_Product.GetPrice();
}

void KSO::RemoveProduct(const std::string& NameProduct)
{
	auto Find_Product = m_AllProduct.GetProduct(NameProduct);
	auto Product_to_remove = std::find(std::begin(m_ProductCart), std::end(m_ProductCart), Find_Product);
	m_ProductCart.erase(Product_to_remove);
	m_TotalPrice -= Find_Product.GetPrice();
}

std::list<Product> KSO::GetCart() const
{
	return m_ProductCart;
}

double KSO::GetPrice() const
{
	return m_TotalPrice;
}

