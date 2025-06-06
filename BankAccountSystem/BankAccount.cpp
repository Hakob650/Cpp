#include <iostream>
#include <string>
#include "BankAccount.h"

BankAccount::BankAccount()
	: accountHolder("Unknown"), accountNumber(0), balance(0.0) {}

BankAccount::BankAccount(const std::string& name,int accNum,double initbal)
{
	accountHolder = name;
	accountNumber = accNum;
	balance = initbal;
}

BankAccount::BankAccount(const BankAccount& other)
	: accountHolder(other.accountHolder), accountNumber(other.accountNumber), balance(other.balance) {}

BankAccount::BankAccount(std::string name, int number, double initialBalance,bool)
	: accountHolder(name), accountNumber(number), balance(initialBalance) {}

BankAccount::~BankAccount()
{
	std::cout<<"Account of "<<accountHolder<<" is destroyed"<<std::endl;
}

void BankAccount::deposit(double amount)
{
	if(amount < 0)
	{
		std::cout<<"Deposit Failed.\n";
		return;
	}
	balance += amount;
}

bool BankAccount::withdraw(double amount)
{
	if(amount > balance)
	{
		std::cout<<"Insufficient balance.\n";
		return false;
	}
	balance -= amount;
	return false;
}

void BankAccount::display() const
{
	std::cout<<"Account Holder: "<<accountHolder<<std::endl;
	std::cout<<"Account Number: "<<accountNumber<<std::endl;
	std::cout<<"Balance: "<<balance<<std::endl;
}

int BankAccount::getAccountNumber() const
{
	return accountNumber;
}





