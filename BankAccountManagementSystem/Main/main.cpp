#include <iostream>
#include "../include/BankSystem.hpp"
#include "../bank_system_exceptions/exceptions.hpp"

int main()
{
    BankSystem bank;

    try
    {
        bank.add_account("Alice", 1001, 500.0);
        bank.add_account("Bob", 1002, 1000.0);

        std::cout << "---All Accounts---\n";
        bank.display_all_accounts();

        std::cout << "---Transferring 200$ from Bob to Alice---\n";
        bank.transfer_funds(1001, 1002, 200);

        std::cout << "---Updated accounts---\n";
        bank.display_all_accounts();

        std::cout << "\n--- Attempting Overdraft ---\n";
        bank.transfer_funds(1001, 1002, 1000.0);
    }
    catch(const BankAccountException& exception)
    {
        std::cerr << "Account Error: " << exception.what() << std::endl;
    }
    catch(const BankSystemException& exception)
    {
        std::cerr << "System Error: " << exception.what() << std::endl;
    }
    catch(const std::exception& exception)
    {
        std::cerr << "Unexpected Error: " << exception.what() << std::endl; 
    }

    return 0;
}