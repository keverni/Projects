#include <iostream>
#include "Worker.h"
#include "Engineer.h"
#include "Medic.h"

void payment(Worker& worker, int hours)
{
	worker.payment(hours);
}


int main()
{
	Engineer engineer(1.5);
	Medic medic(0.5);

	std::cout << medic.GetBalance() << std::endl;
	payment(medic, 5);
	std::cout << medic.GetBalance() << std::endl;
	medic.withdraw(500);
	std::cout << medic.GetBalance() << std::endl;

	std::cout << engineer.GetBalance() << std::endl;
	payment(engineer, 3);
	std::cout << engineer.GetBalance() << std::endl;	
	engineer.withdraw(500);
	std::cout << engineer.GetBalance() << std::endl;

	return 0;
}