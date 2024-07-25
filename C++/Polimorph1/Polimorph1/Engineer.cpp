#include "Engineer.h"

Engineer::Engineer(double k) :
	Worker(k)
{
}

Engineer::~Engineer()
{
}

void Engineer::payment(int hours)
{
	m_balance += (m_payHour * hours) * m_koef;
}