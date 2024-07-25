#include "Worker.h"
#include <iostream>

Worker::Worker(double k) :
	m_balance(0),
	m_koef(k),
	m_payHour(100)
{
}

Worker::~Worker()
{
}

int Worker::GetBalance() const
{
	return m_balance;
}

void Worker::withdraw(int count)
{
	m_balance -= count;
}