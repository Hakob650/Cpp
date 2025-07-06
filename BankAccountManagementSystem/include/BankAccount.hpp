#pragma once
#include <string>

class BankAccount
{
private:
        std::string account_holder;
        int account_number;
        double account_balance;
public:
        BankAccount();
        BankAccount(const std::string& holder, int number, double balance);
        BankAccount(const BankAccount& other);
        ~BankAccount();

        void deposit(double amount);
        bool withdraw(double amount);
        void display() const;

        int get_account_number() const;
        std::string get_account_holder() const;
        double get_account_balance() const;
};
