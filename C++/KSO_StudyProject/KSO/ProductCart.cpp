#include "ProductCart.h"

void ProductCart::AddProduct(const Product& product)
{
	m_ListOfProduct.push_back(product);
}

bool ProductCart::RemoveProduct(const Product& product)
{
	auto FindProductToRemove = std::find_if(m_ListOfProduct.begin(), m_ListOfProduct.end(), [&product](const Product& product_1) {
		return product.m_Name == product_1.m_Name;
	});
	if (FindProductToRemove != m_ListOfProduct.end())
	{
		m_ListOfProduct.erase(FindProductToRemove);
		return 1;
	}
	return 0;
}

std::vector<Product> ProductCart::GetCart()
{
	return m_ListOfProduct;
}