#include "Game.h"
#include <random>

Game::Game(long int leftRange, long int rightRange)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(leftRange,rightRange);
	
	m_Number = dist(gen);
}

int Game::start(long int UserNumber)
{
	return RightNumber(UserNumber);
}

int Game::RightNumber(long int UserNum)
{
	if (m_Number == UserNum)
	{
		return 0;
	}
	if (m_Number > UserNum)
	{
		return 1;
	}
	if (m_Number < UserNum)
	{
		return -1;
	}
	
}
