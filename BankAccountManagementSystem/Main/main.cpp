#include "BankSystem.h"

int main()
{
	BankSystem bank;
	
	bank.add_account("Alice",1001,500.0);
	bank.add_account("David",1002,1000.0);

	bank.displayAllAccounts();

	bank.find_account(1001)->deposit(200);
	bank.find_account(1002)->withdraw(150);

	bank.transfer_funds(1002,1001,300);

	bank.displayAllAccounts();

	return 0;
}
