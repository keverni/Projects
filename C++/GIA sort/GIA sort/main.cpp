#include <iostream>
#include "People.h"
#include <vector>
#include <algorithm>

int main()
{
	std::vector<People> peoples = {
		People("Jessica", 25, 160),
		People("Maik", 58, 230),
		People("Jessica", 18, 200),
		People("Kain", 29, 143),
		People("Michael", 34, 230),
		People("Key", 44, 230)
	};

	std::sort(peoples.begin(), peoples.end(), [](People& people1, People& people2) {return people1.Mark < people2.Mark; });
	for (auto i = peoples.begin(); i != peoples.end(); ++i)
	{
		std::cout << i->Name << "\t" << i->Age << "\t" << i->Mark << std::endl;
	}
	return 0;
}