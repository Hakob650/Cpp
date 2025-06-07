#include <string>

class BankAccount
{
private:
    std::string accountHolder;
    int accountNumber;
    double balance;
public:
    BankAccount();
    BankAccount(std::string name,int accNum,double bal);
    BankAccount(const BankAccount& other);
    ~BankAccount();

    void deposit(double amount);
    bool withdraw(double amount);
    void display() const;

    int getAccountNumber() const;
};

#endif
