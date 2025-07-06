#pragma once
#include <vector>
#include "BankAccount.hpp"

class BankSystem
{
private:
        std::vector<BankAccount*> accounts;
public: 
        void add_account(const std::string& name, int accountNumber, double initial_balance);
        BankAccount* find_account(int accountNumber);
        void transfer_funds(int sender, int reciever, double amount);
        void display_all_accounts() const;

        std::string get_account_holder() const;
        int get_account_number() const;
        double get_account_balance() const;
};