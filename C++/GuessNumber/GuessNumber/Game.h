#pragma once

class Game
{
public:
	Game(long int leftRange, long int rightRange);

	void start(long int UserNumber);

private:
	bool RightNumber(long int UserNum);

private:
	long int m_Number;
	
};

