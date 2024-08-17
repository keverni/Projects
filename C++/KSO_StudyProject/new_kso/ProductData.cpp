#include "ProductData.h"

#include <stdexcept>
#include <algorithm>

ProductData::ProductData()
{
	m_Product_Data = 
	{
		Product("Apple", 10),
		Product("Juice", 50),
		Product("Chips", 120),
		Product("Cola", 135),
		Product("Bread", 40)
	};
}

const Product& ProductData::GetProduct(const std::string& ProductName) const
{
	const auto Product_ID = std::hash<std::string>{}(ProductName);
	auto find_product = std::find_if(std::begin(m_Product_Data), std::end(m_Product_Data), [&ProductName, &Product_ID](const Product& product) {
		return product.m_Product_id == Product_ID;
	});
	if (find_product != std::end(m_Product_Data))
	{
		return *find_product;
	}
	throw std::invalid_argument("Invalid product");
}
