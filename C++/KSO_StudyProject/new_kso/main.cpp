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
			try
			{
				kso.AddProduct(Product);
			}
			catch (const std::invalid_argument& ex)
			{
				std::cout << ex.what() << std::endl;
				continue;
			}
			std::cout << "Product append in cart" << std::endl;
		}
		else if (Command == 2)
		{
			std::string Product;
			std::cout << "Input name of product to remove: ";
			std::cin >> Product;
			try
			{
				kso.RemoveProduct(Product);
			}
			catch (const std::exception& ex)
			{
				std::cout << ex.what() << std::endl;
				continue;
			}
			std::cout << "Product is successfully removed!" << std::endl;
		}
		else if (Command == 3)
		{
			auto ProductCart = kso.GetCart();
			std::cout << "Name\tPrice" << std::endl;
			for (auto el : ProductCart)
			{
				std::cout << el.GetName() << "\t" << el.GetPrice()<< "\t" << std::endl;
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