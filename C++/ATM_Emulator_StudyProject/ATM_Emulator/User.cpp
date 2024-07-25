#include "User.h"

bool User::operator==(const User& obj)
{
	return (m_NumberCard == obj.m_NumberCard && m_PINCode == obj.m_PINCode);
}

void User::CreateUser(std::string NumberCard, int PIN)
{
	m_NumberCard = NumberCard;
	m_PINCode = PIN;
	m_balance = 0;
}
void User::deposit(int amount)
{
	m_balance += amount;
}
void User::withdraw(int amount)
{
	if ((m_balance - amount) >= 0)
	{
		m_balance -= amount;
	}
	else
	{
		std::cout << "Error withdraw! Check balance";
	}
}
int  User::GetBalance() const
{
	return m_balance;
}