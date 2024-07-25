#pragma once

#include "Supplies.h"
#include "ProductCard.h"
#include <vector>

enum class Result
{
	OK = 0,
	NoMoney,
	NoIngredients,
	NoProductCard,
};

class CoffeeMachine
{
public:
	CoffeeMachine(double init_coffee, double init_milk, double init_sugar, int init_balance);

	Result ChoiceDrink(DrinkType drink);
	
private:
	bool CheckIngredients(double coffee, double milk, double sugar);
	bool CheckBalance(int money);

private:
	int m_Balance;
	Supplies m_Supplies;
	std::vector<ProductCard> m_ProductCards;
};
