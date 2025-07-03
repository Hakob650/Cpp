#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H

#include <vector>
#include "BankAccount.h"

class BankSystem
{
private:
	std::vector<BankAccount*> accounts;
public:
	void add_account(const std::string& name,int accountNumber,double initialBalance);
	BankAccount* find_account(int accountNumber);
	void transfer_funds(int senderAcc,int recieverAcc,double amount);
	void displayAllAccounts();
	~BankSystem();
	
};

#endif
