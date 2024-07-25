#include "ATM.h"

void ATM::CreateUser(std::string NumberCard, int PIN)
{
	UpdateUser();
	m_CurrentUser.CreateUser(NumberCard, PIN);
	m_ListUsers.push_back(m_CurrentUser);
}
bool ATM::ExistingUser(std::string NumberCard, int PIN)
{
	UpdateUser();
	User obj;
	obj.CreateUser(NumberCard, PIN);
	for (int i = 0; i < m_ListUsers.size(); ++i)
	{
		if (m_ListUsers[i] == obj)
		{
			m_CurrentUser = m_ListUsers[i];
			return 1;
		}
	}
	return 0;
}
void ATM::deposit(int amount)
{
	m_CurrentUser.deposit(amount);
}
void ATM::withdraw(int amount)
{
	m_CurrentUser.withdraw(amount);
}
int  ATM::GetBalance() const
{
	return m_CurrentUser.GetBalance();
}


void ATM::UpdateUser()
{
	if (!m_ListUsers.empty())
	{
		for (auto elem = std::begin(m_ListUsers); elem != std::end(m_ListUsers); ++elem)
		{
			if (*elem == m_CurrentUser)
			{
				*elem = m_CurrentUser;
			}
		}
	}
}

