#include "KSO.h"

KSO::KSO()
{
	m_AllProduct = 
	{
		Product("Apple", 10, 1),
		Product("Juice", 50),
		Product("Chips", 120),
		Product("Potato", 35, 1),
		Product("Milk", 135),
		Product("Bread", 40)
	};
}

bool KSO::AddProduct(std::string NameProduct)
{
	auto FindProductToAppend = std::find_if(m_AllProduct.begin(), m_AllProduct.end(), [&NameProduct](const Product& product) {
		return product.m_Name == NameProduct;
	});
	if (FindProductToAppend != m_AllProduct.end())
	{
		if (FindProductToAppend->m_Weight != 0)
		{
			Product Product_To_Append = *FindProductToAppend;
			std::cout << "Enter weight: ";
			std::cin >> Product_To_Append.m_Weight;
			Product_To_Append.m_Price *= Product_To_Append.m_Weight;
			m_ProductCart.AddProduct(Product_To_Append);
			m_TotalPrice += Product_To_Append.m_Price;
		}
		else
		{
			m_ProductCart.AddProduct(*FindProductToAppend);
			m_TotalPrice += FindProductToAppend->m_Price;
		}
		return 1;
	}
	return 0;

	
}
bool KSO::RemoveProduct(std::string NameProduct) // сделать нормальное удаление для весового товара
{
	auto FindProductToRemove = std::find_if(m_AllProduct.begin(), m_AllProduct.end(), [&NameProduct](const Product& product) {
		return product.m_Name == NameProduct;
	});
	if (m_ProductCart.RemoveProduct(*FindProductToRemove))
	{
		m_TotalPrice -= FindProductToRemove->m_Price;
		return 1;
	}
	return 0;
	
}
std::vector<Product> KSO::GetCart()
{
	return m_ProductCart.GetCart();
	
}
int KSO::GetPrice()
{
	return m_TotalPrice;
}