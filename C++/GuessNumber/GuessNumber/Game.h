#pragma once

class Game
{
public:
	Game(long int leftRange, long int rightRange);

	int start(long int UserNumber);

private:
	int RightNumber(long int UserNum);

private:
	long int m_Number;
	
};

