#pragma once
#include <string>
#include <iostream>

class User
{
public:
	bool operator==(const User& obj);

	void CreateUser(std::string NumberCard, int PIN);
	void deposit(int amount);
	void withdraw(int amount);
	int  GetBalance() const;
	
private:
	std::string m_NumberCard;
	int         m_PINCode;
	int			m_balance;
};

