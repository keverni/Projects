#include "Medic.h"

Medic::Medic(double k) :
	Worker(k)
{
}

Medic::~Medic()
{
}

void Medic::payment(int hours)
{
	m_balance += (m_payHour * hours) * m_koef;
}