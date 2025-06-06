#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <initializer_list>

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
	BankAccount(const std::string& name,std::initializer_list<double> values);
	~BankAccount();

	void deposit(double amount);
	bool withdraw(double amount);
	void display() const;

	int getAccountNumber() const;
};

#endif
	
