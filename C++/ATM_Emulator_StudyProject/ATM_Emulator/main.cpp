#include <iostream>
#include <string>
#include "User.h"
#include "ATM.h"

void NewUser(ATM& atm)
{
	std::string NumberCard = "";
	int PIN = 0;
	while (1)
	{
		std::cout << "Enter NumberCard for registrations: ";
		std::cin >> NumberCard;
		if (NumberCard == "")
		{
			std::cout << "Enter NumberCard" << std::endl;
			continue;
		}
		else
		{
			break;
		}
	}

	std::cout << std::endl;

	while (1)
	{
		std::cout << "Enter your PIN-code for registrations: ";
		std::cin >> PIN;
		if (PIN % 1000 != 0)
		{
			break;
		}
		else
		{
			std::cout << "Incorrect PIN-code. It must consist of 4 digits!" << std::endl;
			continue;
		}
	}
	
	atm.CreateUser(NumberCard, PIN);
}

int main()
{
	std::cout << "Hi! It's ATM.";
	ATM atm;
	NewUser(atm);
	int Choose = 0;

	while (1)
	{
		std::cout << "Choose option: 1 - Deposit, 2 - Withdraw, 3 - Create new user, 4 - Show balance,  5 - Enter to existing user, 6 - exit" << std::endl;
		std::cin >> Choose;
		if (Choose == 1)
		{
			int amount;
			std::cout << "Enter amount to deposit: ";
			std::cin >> amount;
			atm.deposit(amount);
		}
		else if (Choose == 2)
		{
			int amount;
			std::cout << "Enter amount to withdraw: ";
			std::cin >> amount;
			atm.withdraw(amount);
		}
		else if (Choose == 3)
		{
			NewUser(atm);
		}
		else if (Choose == 4)
		{
			std::cout << "Your balance: " << atm.GetBalance() << std::endl;
		}
		else if (Choose == 5)
		{
			std::string NumberCard = "";
			int Pin = 0;

			std::cout << "Enter NumberCard to login: ";
			std::cin >> NumberCard;
			std::cout << std::endl;

			std::cout << "Enter PIN-code to login: ";
			std::cin >> Pin;

			if (atm.ExistingUser(NumberCard, Pin))
			{
				std::cout << "Good!!! You are welcome!" << std::endl;
				continue;
			}
			else
			{
				std::cout << "We can't find your account!";
				continue;
			}
		}
		else if (Choose == 6)
		{
			break;
		}
	}

	return 0;
}