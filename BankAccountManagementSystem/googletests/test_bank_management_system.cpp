#include <gtest/gtest.h>
#include "../include/BankAccount.hpp"
#include "../include/BankSystem.hpp"
#include "../bank_system_exceptions/exceptions.hpp"

TEST(BankAccount_Tests, Deposit_Increases_Balance)
{
    BankAccount account("Name", 12345, 1000.0);
    account.deposit(500.0);
    EXPECT_DOUBLE_EQ(account.get_account_balance(), 1500.0);
}

TEST(BankAccount_Tests, DepositNegativeThrows)
{
    BankAccount account("Name", 12345, 1000.0);
    EXPECT_THROW(account.deposit(-100.0), std::exception);
}

TEST(BankAccount_Tests, WithdrawDecreasesBalance)
{
    BankAccount account("Name", 12345, 1000.0);
    account.withdraw(500);
    EXPECT_DOUBLE_EQ(account.get_account_balance(), 500.0);
}

TEST(BankAccount_Tests, WithdrawNegativeThrows)
{
     BankAccount account("Name", 12345, 1000.0);
     EXPECT_THROW(account.withdraw(-100.0), std::exception);
}

TEST(BankAccount_Tests, WithdrawTooMuchThrowsInsufficientFunds)
{
     BankAccount account("Name", 12345, 1000.0);
     EXPECT_THROW(account.withdraw(3000.0), std::exception);
}

TEST(BankAccount_Tests, GetAccountHolderReturnsHoldersName)
{
    BankAccount account("Name", 12345, 1000.0);
    EXPECT_EQ(account.get_account_holder(), "Name");
}

TEST(BankAccount_Test, GetAccountBalanceReturnsBalance)
{
     BankAccount account("Name", 12345, 1000.0);
     EXPECT_DOUBLE_EQ(account.get_account_balance(), 1000.0);
}

TEST(BankAccount_Tests, GetAccountNumberReturnsAccountNumber)
{
    BankAccount account("Name", 12345, 1000.0);
    EXPECT_EQ(account.get_account_number(), 12345);
}

TEST(BankAccount_Tests, CopyConstructorPerformsDeepCopy)
{
    BankAccount original("Name", 12345, 1000.0);
    BankAccount copy(original);

    EXPECT_EQ(copy.get_account_holder(), "Name");
    EXPECT_EQ(copy.get_account_number(), 12345);
    EXPECT_DOUBLE_EQ(copy.get_account_balance(), 1000.0);
}

TEST(BankSystem_Tests, AddAccountAndFind)
{
    BankSystem bank;
    bank.add_account("Name", 1001, 500.0);

    BankAccount* account = bank.find_account(1001);
    
    ASSERT_NE(account, nullptr);
    EXPECT_EQ(account->get_account_holder(), "Name");
    EXPECT_EQ(account->get_account_number(), 1001);
    EXPECT_DOUBLE_EQ(account->get_account_balance(), 500.0);
}

TEST(BankSystem_Tests, FindAccountThrowsIfNotFound)
{
    BankSystem bank;
    bank.add_account("Name", 1000, 1000.0);
    EXPECT_THROW(bank.find_account(1000), BankSystemException);
}

TEST(BankSystem_Tests, TransferFundsSuccess)
{
    BankSystem bank;
    bank.add_account("Name1", 1000, 1000.0);
    bank.add_account("Name2", 1001, 2000.0);

    bank.transfer_funds(1001, 1000, 500.0);

    BankAccount* sender = bank.find_account(1001);
    BankAccount* reciever = bank.find_account(1000);

    EXPECT_DOUBLE_EQ(sender->get_account_balance(), 1500.0);
    EXPECT_DOUBLE_EQ(reciever->get_account_balance(), 1500.0);
}

TEST(BankSystem_Tests, TransferFundsThrowsOnMissingAccount)
{
    BankSystem bank;
    bank.add_account("Name1", 1000, 2500.0);

    EXPECT_THROW(bank.transfer_funds(1000,9999,1000.0), BankSystemException);
    EXPECT_THROW(bank.transfer_funds(9999, 1000, 1000.0), BankSystemException);
}

TEST(BankSystem_Tests, TransferFundsThrowsOnInsufficientAmount)
{
    BankSystem bank;
    bank.add_account("Name1", 1000, 3000.0);
    bank.add_account("Name2", 1001, 2000.0);

    EXPECT_THROW(bank.transfer_funds(1000, 10001, 5000.0), BankSystemException);
}
