#include <iostream>
#include "BankAccount.h"

BankAccount::BankAccount()
    : accountHolder("Unknown"), accountNumber(0), balance(0.0) {}

BankAccount::BankAccount(std::string name,int accNum, double bal)
    : accountHolder(name), accountNumber(accNum), balance(bal) {}

BankAccount::BankAccount(const BankAccount& other)
   : accountHolder(other.accountHolder), accountNumber(other.accountNumber), balance(other.balance) {}

BankAccount::~BankAccount()
{
    std::cout<<"Account of "<<accountHolder<<" is destroyed"<<std::endl;
}

void BankAccount::deposit(double amount)
{
    if(amount < 0)
    {
        std::cout<<"Insufficient balance"<<std::endl;
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
    return true;
}

void BankAccount::display() const
{
    std::cout<<"Account Holder: "<<accountHolder<<std::endl;
    std::cout<<"Account Holder: "<<accountNumber<<std::endl;
    std::cout<<"Balance: "<<balance<<std::endl;
} 

int BankAccount::getAccountNumber() const
{
    return accountNumber;
}



