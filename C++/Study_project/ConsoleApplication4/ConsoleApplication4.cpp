#include <iostream>

class Account
{
protected:
    double balance;

public:
    Account(double initBalance = 0)
    {
        balance = initBalance;
    }

    double getBal()
    {
        return balance;
    }

    void winthdraw(double amount)
    {
        if (balance > amount)
        {
            balance -= amount;
        }
    }

    void deposit(double amount)
    {
        balance += amount;
    }
};

class CheckingAccount : public Account
{
public:

    CheckingAccount(double initBalance = 0)
    {
        balance = initBalance;
        fee = 0.2;
    }

    void winthdraw(double amount, int b)
    {
        if (balance > amount)
        {
            balance = balance - amount - fee;
        }
        b += balance;
    }

private:
    double fee;
};

int main()
{
    CheckingAccount b;
    b.winthdraw(2.0);
}
