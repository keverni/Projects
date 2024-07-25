#pragma once

enum DrinkType
{
	Invalid = 0,
	Cappuccino,
	Raf,
	Latte,
	Exit,
};

struct ProductCard
{
	DrinkType ID;
	int    Price;
	double Coffee;
	double Milk;
	double Sugar;

	ProductCard(DrinkType id, int price, double coffee, double milk, double sugar) :
		ID(id),
		Price(price),
		Coffee(coffee),
		Milk(milk),
		Sugar(sugar)
	{
	}
};