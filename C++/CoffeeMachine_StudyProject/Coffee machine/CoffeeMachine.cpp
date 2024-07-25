#include "CoffeeMachine.h"

CoffeeMachine::CoffeeMachine(double init_coffee, double init_milk, double init_sugar, int init_balance) :
	m_Balance(init_balance)
{
	m_Supplies.Coffee = init_coffee;
	m_Supplies.Milk   = init_milk;
	m_Supplies.Sugar  = init_sugar;

	m_ProductCards.push_back(ProductCard(DrinkType::Cappuccino, 100, 0.02, 0.05, 0.02));
	m_ProductCards.push_back(ProductCard(DrinkType::Raf,        180, 0.01, 0.08, 0.02));
	m_ProductCards.push_back(ProductCard(DrinkType::Latte,      165, 0.01, 0.1,  0.02));
}

bool CoffeeMachine::CheckIngredients(double coffee, double milk, double sugar)
{
	return ((m_Supplies.Sugar - sugar) >= 0 && (m_Supplies.Milk - milk) >= 0 && (m_Supplies.Coffee - coffee) >= 0);
}

bool CoffeeMachine::CheckBalance(int money)
{
	return (m_Balance - money) >= 0;
}

Result CoffeeMachine::ChoiceDrink(DrinkType drink)
{
	for (int i = 0; i < m_ProductCards.size(); ++i)
	{
		if (m_ProductCards[i].ID == drin k)
		{
			if (CheckBalance(m_ProductCards[i].Price))
			{
				if (CheckIngredients(m_ProductCards[i].Coffee, m_ProductCards[i].Milk, m_ProductCards[i].Sugar))
				{
					m_Balance -= m_ProductCards[i].Price;

					m_Supplies.Coffee -= m_ProductCards[i].Coffee;
					m_Supplies.Milk   -= m_ProductCards[i].Milk;
					m_Supplies.Sugar  -= m_ProductCards[i].Sugar;

					return Result::OK;
				}

				return Result::NoIngredients;
			}

			return Result::NoMoney;
		}
	}

	return Result::NoProductCard;
}
