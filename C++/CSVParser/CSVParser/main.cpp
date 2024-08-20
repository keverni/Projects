#include <iostream>
#include "CSVParser.h"

int main()
{
	try
	{
		CSVParser parser("test.csv");
	}
	catch (const std::runtime_error& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}