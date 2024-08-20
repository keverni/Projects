#include "Game.h"
#include <random>

Game::Game(long int leftRange, long int rightRange)
{
	std::random_device rd;   // non-deterministic generator
	std::mt19937 gen(rd());  // to seed mersenne twister.
	std::uniform_int_distribution<> dist(leftRange,rightRange);
	
	m_Number = dist(gen);
}

void Game::start(long int UserNumber)
{
	if (!RightNumber(UserNumber))
	{
		throw std::invalid_argument("Wrong number!");
	}
}

bool Game::RightNumber(long int UserNum)
{
	return m_Number == UserNum;
}
