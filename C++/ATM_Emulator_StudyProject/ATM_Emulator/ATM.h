#pragma once
#include "User.h"
#include <string>
#include <vector>
#include <iterator>

class ATM
{
public:

	void CreateUser(std::string NumberCard, int PIN);
	bool ExistingUser(std::string NumberCard, int PIN);
	void deposit(int amount);
	void withdraw(int amount);
	int  GetBalance() const;

private:
	void UpdateUser();

private:
	std::vector<User> m_ListUsers;
	User              m_CurrentUser;
};

