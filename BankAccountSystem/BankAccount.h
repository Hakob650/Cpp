#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

class BankAccount
{
private:
	std::string accountHolder;
	int accountNumber;
	double balance;
public:
	BankAccount();
	BankAccount(const std::string& name,int accNum,double initbal);
	BankAccount(const BankAccount& other);
	BankAccount(std::string name,int accNum,double initialBal,bool);
	~BankAccount();

	void deposit(double amount);
	bool withdraw(double amount);
	void display() const;

	int getAccountNumber() const;
};

#endif
	
