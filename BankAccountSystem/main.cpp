#include <iostream>
#include "BankSystem.hpp"

int main() {
    // Create bank system
    std::cout << "\n=== Creating Bank System ===\n";
    BankSystem bank;

    // Test account creation
    std::cout << "\n=== Testing Account Creation ===\n";
    bank.add_account("Alice", 1001, 1000.0);
    bank.add_account("Bob", 1002, 2000.0);
    bank.add_account("Charlie", 1003, 1500.0);
    bank.displayAllAccounts();

    // Test deposits
    std::cout << "\n=== Testing Deposits ===\n";
    bank.find_account(1001)->deposit(500.0);
    bank.find_account(1002)->deposit(1000.0);
    bank.displayAllAccounts();

    // Test withdrawals
    std::cout << "\n=== Testing Withdrawals ===\n";
    bank.find_account(1001)->withdraw(200.0);
    bank.find_account(1002)->withdraw(500.0);
    bank.displayAllAccounts();

    // Test transfers
    std::cout << "\n=== Testing Transfers ===\n";
    bank.transfer_funds(1002, 1001, 300.0);
    bank.displayAllAccounts();

    // Test invalid operations
    std::cout << "\n=== Testing Invalid Operations ===\n";
    // Try to withdraw more than balance
    bank.find_account(1003)->withdraw(2000.0);
    // Try to transfer more than available
    bank.transfer_funds(1001, 1002, 5000.0);
    // Try to find non-existent account
    if (!bank.find_account(9999)) {
        std::cout << "Account 9999 not found (as expected)\n";
    }

    // Final state
    std::cout << "\n=== Final Bank State ===\n";
    bank.displayAllAccounts();

    return 0;
}
