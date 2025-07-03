#include "../include/BankSystem.h"
#include <iostream>

BankSystem::~BankSystem()
{
	for(size_t i = 0; i < accounts.size(); ++i)
	{
		delete accounts[i];
	}
}
void BankSystem::add_account(const std::string& name,int accNum,double initialBalance)
{
	BankAccount* new_account = new BankAccount(name,accNum,initialBalance);
	accounts.push_back(new_account);
}

BankAccount* BankSystem::find_account(int accNum)
{
	for(size_t i = 0; i < accounts.size(); ++i)
	{
		if(accounts[i]->getAccountNumber() == accNum)
		{
			return accounts[i];	
		}
	}
	std::cout<<"Account "<<accNum<<"not found";
	return nullptr;
}

void BankSystem::transfer_funds(int senderAcc,int recieverAcc,double amount)
{
	BankAccount* sender = find_account(senderAcc);
	BankAccount* reciever = find_account(recieverAcc);

	if(sender && reciever)
	{
		if(sender->withdraw(amount))
		{
			reciever->deposit(amount);
			std::cout<<"Transferred: "<<amount<<std::endl;
		}
	}
}

void BankSystem::displayAllAccounts()
{
	std::cout<<"All Bank Accounts"<<std::endl;
	for(size_t i = 0; i < accounts.size(); ++i)
	{
		accounts[i]->display();
	}
}


	 
