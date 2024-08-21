#include <iostream>
#include "Game.h"

int main()
{
	std::cout << "Hello, its game 'Guess Number' " << std::endl;

	long int leftRange, rightRange, number;
	
	std::cout << "Enter range of generate number: ";
	std::cin >> leftRange >> rightRange;
	
	Game game(leftRange, rightRange);
	
	for (;;)
	{
		std::cout << "Enter number: ";
		std::cin >> number;

		int ResultGame = game.start(number);
		if (ResultGame == 0)
		{
			std::cout << "You win! Congratulations!" << std::endl;
			break;
		}
		else if (ResultGame == 1)
		{
			std::cout << "My number is higher!" << std::endl;
		}
		else if (ResultGame == -1)
		{
			std::cout << "My number is smaller!" << std::endl;
		}
	}

	return 0;
}