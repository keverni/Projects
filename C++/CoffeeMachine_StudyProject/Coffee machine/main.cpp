#include <iostream>
#include <string>
#include "CoffeeMachine.h"

std::string GetDrinkName(DrinkType type)
{
	if (type == DrinkType::Cappuccino)
	{
		return "Cappuccino";
	}
	else if (type == DrinkType::Raf)
	{
		return "Raf";
	}
	else if (type == DrinkType::Latte)
	{
		return "Latte";
	}

	return "Invalid";
}

int CinRead()
{
	std::string str;
	std::cin >> str;

	int num = 0;

	try
	{
		num = std::stoi(str);
	}
	catch (const std::logic_error& )
	{
		//
	}

	return num;
}

bool CheckOnValidDrink(int user_drink)
{
	return (user_drink < DrinkType::Exit && user_drink > DrinkType::Invalid);
}

int main()
{
	std::cout << "Hi! Its coffee machine! Please input money: ";
	int money = CinRead();

	std::cout << std::endl;

	CoffeeMachine machine(1.0, 1.0, 1.0, money);

	int user_drink = 0;
	while (user_drink != DrinkType::Exit)
	{
		std::cout << "Choose coffee (1 - Cappuccino, 2 - Raf, 3 - Latte, 4 - exit): ";
		user_drink = CinRead();

		if (!CheckOnValidDrink(user_drink))
		{
			std::cout << "Invalid drink!" << std::endl;
			continue;
		}

		Result res = machine.ChoiceDrink((DrinkType) user_drink);
		if (res == Result::OK)
		{
			std::cout << "Your Coffee: " << GetDrinkName((DrinkType)user_drink) << " is ready, Sir -> \n\n";
		}
		else if (res == Result::NoMoney)
		{
			std::cout << "Money is over!\n";
			break;
		}
		else if (res == Result::NoIngredients)
		{
			std::cout << "Ingredients is over. Please call administrator.\n";
			break;
		}
	}

	std::cout << "Bye bye!";
	return 0;
}
