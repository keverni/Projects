#pragma once

class Worker
{

public:
	Worker(double k);
	virtual ~Worker();

	virtual void payment(int hours) = 0;
	int GetBalance() const;
	void withdraw(int count);

protected:
	int m_balance;
	double m_koef;
	int m_payHour;
};

