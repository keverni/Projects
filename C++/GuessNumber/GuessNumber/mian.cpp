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
		
		try
		{
			game.start(number);
			break;
		}
		catch (const std::invalid_argument& ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}

	std::cout << "You win! Congratulations!" << std::endl;

	return 0;
}