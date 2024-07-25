#include <iostream>
#include "KSO.h"

int main()
{
	KSO kso;
	int Command;
	while (true)
	{
		std::cout << "Enter command: 1 - Add product, 2 - Remove product, 3 - Show productcart, 4 - Pay: ";
		std::cin >> Command;
		if (Command == 1)
		{
			std::string Product;
			std::cout << "Input name of product to append: ";
			std::cin >> Product;
			if (kso.AddProduct(Product))
			{
				std::cout << "Product append in cart" << std::endl;
			}
			else
			{
				std::cout << "Invalid product!" << std::endl;
			}
		}
		else if (Command == 2)
		{
			std::string Product;
			std::cout << "Input name of product to remove: ";
			std::cin >> Product;
			if (kso.RemoveProduct(Product))
			{
				std::cout << "Product is successfully removed!" << std::endl;
			}
			else
			{
				std::cout << "Invalid product!" << std::endl;
			}
		}
		else if (Command == 3)
		{
			auto ProductCart = kso.GetCart();
			std::cout << "Name\tPrice\tWeight" << std::endl;
			for (auto el : ProductCart)
			{
				if (el.m_Weight == 0)
				{
					std::cout << el.m_Name << "\t" << el.m_Price << "\t" << std::endl;
				}
				else
				{
					std::cout << el.m_Name << "\t" << el.m_Price << "\t" << el.m_Weight << "\t" << std::endl;
				}
			}
			std::cout << std::endl << "Total price: " << kso.GetPrice() << std::endl;
			
		}
		else if (Command == 4)
		{
			std::string ask;
			std::cout << "Do you want to pay? ";
			std::cin >> ask;
			if (ask == "Yes" || ask == "yes")
			{
				std::cout << "Success!";
				break;
			}
			else if (ask == "No" or ask == "no")
			{
				continue;
			}
		}
		else
		{
			std::cout << "Invalid command!!!" << std::endl;
			continue;
		}
	}
	std::cout << "Thank you! Bye :)" << std::endl;
	return 0;
}