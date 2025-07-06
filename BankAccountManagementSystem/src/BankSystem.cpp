#include <iostream>
#include "../include/BankSystem.hpp"
#include "../include/BankAccount.hpp"
#include"../bank_system_exceptions/exceptions.hpp"

void BankSystem::add_account(const std::string& name, int accountNumber, double initial_balance)
{
    BankAccount* account = new BankAccount(name, accountNumber, initial_balance);

    if(!account)
    {
        throw BankSystemException("Account Creation Failed!");
    }

    accounts.push_back(account);
}

BankAccount* BankSystem::find_account(int accountNumber)
{
    for(size_t i = 0; i < accounts.size(); ++i)
    {
        if(accounts[i]->get_account_number() != accountNumber)
        {
            throw BankSystemException("Account Numbers aren't the same");
            return nullptr;
        }
        return accounts[i];
    }
}

void BankSystem::transfer_funds(int sender, int reciever, double amount)
{
    BankAccount* _sender = find_account(sender);
    BankAccount* _reciever = find_account(reciever);

    if(!_sender && !_reciever)
    {
        throw BankSystemException("Sender and reciever not found");
    }
    else
    {
        if(_sender->withdraw(amount))
        {
            _reciever->deposit(amount);
            std::cout << "Transferred Successfully!" << std::endl;
        }
        else
        {
            throw BankSystemException("Transfer Failed!");
        }
    }
}

void BankSystem::display_all_accounts() const
{
    for(size_t i = 0; i < accounts.size(); ++i)
    {
        accounts[i]->display();
    }
}


