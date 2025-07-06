#include <iostream>
#include "../include/BankAccount.hpp"
#include "../bank_system_exceptions/exceptions.hpp"


BankAccount::BankAccount()
    : account_holder("Unknown"), account_number(0), account_balance(0.0) {}

BankAccount::BankAccount(const std::string& name, int accountNumber, double initial_balance)
    : account_holder(name), account_number(accountNumber), account_balance(initial_balance) {}

BankAccount::BankAccount(const BankAccount& other)
{
    account_holder = other.account_holder;
    
    account_number = other.account_number;
    
    account_balance = other.account_balance;
}

BankAccount::~BankAccount()
{
    std::cout << "Account is Deleted" << std::endl; 
}

void BankAccount::deposit(double amount)
{
    if(amount < 0)
    {
        throw BankAccountException("Invalid balance for deposit");
    }
    
    account_balance += amount;
    
    std::cout << "Deposit is done successfully" <<  account_balance << std::endl;
}

bool BankAccount::withdraw(double amount)
{
    if(amount > account_balance)
    {
        throw BankAccountException("Invalid balance for withdrawal");
        
        return false;
    }
    
    account_balance -= amount;
    
    std::cout << "Withdrawal is done successfully" << std::endl;
    
    return true;
}

void BankAccount::display() const
{
    std::cout << "account holder: " << account_holder << std::endl;

    std::cout << "account number: " << account_number << std::endl;

    std::cout << "account balance: " << account_balance << std::endl;
}

int BankAccount::get_account_number() const
{
    return account_number;
}

std::string BankAccount::get_account_holder() const
{
    return account_holder;
}

double BankAccount::get_account_balance() const
{
    return account_balance;
}

