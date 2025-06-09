#include <iostream>
#include "BankSystem.hpp"

int main() {
   
    std::cout << "\n=== Creating Bank System ===\n";
    BankSystem bank;

    std::cout << "\n=== Testing Account Creation ===\n";
    bank.add_account("Alice", 1001, 1000.0);
    bank.add_account("Bob", 1002, 2000.0);
    bank.add_account("Charlie", 1003, 1500.0);
    bank.displayAllAccounts();

    std::cout << "\n=== Testing Deposits ===\n";
    bank.find_account(1001)->deposit(500.0);
    bank.find_account(1002)->deposit(1000.0);
    bank.displayAllAccounts();

    std::cout << "\n=== Testing Withdrawals ===\n";
    bank.find_account(1001)->withdraw(200.0);
    bank.find_account(1002)->withdraw(500.0);
    bank.displayAllAccounts();

    std::cout << "\n=== Testing Transfers ===\n";
    bank.transfer_funds(1002, 1001, 300.0);
    bank.displayAllAccounts();

    std::cout << "\n=== Testing Invalid Operations ===\n";
    
    bank.find_account(1003)->withdraw(2000.0);
  
    bank.transfer_funds(1001, 1002, 5000.0);
    
    if (!bank.find_account(9999)) {
        std::cout << "Account 9999 not found (as expected)\n";
    }

    std::cout << "\n=== Final Bank State ===\n";
    bank.displayAllAccounts();

    return 0;
}
