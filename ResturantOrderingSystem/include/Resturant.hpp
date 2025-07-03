#ifndef RESTURANT_HPP
#define RESTURANT_HPP

#include <vector>
#include <string>
#include "Customers.hpp"
#include "Menu.hpp"

class Resturant 
{
private:
    Menu menu;
    std::vector<Customer*> customers;
    std::vector<Order> orders;
public:

    Resturant();
    Resturant(const Resturant& other);
    Resturant& operator=(const Resturant& other);
    Resturant(Resturant&& other) noexcept;
    Resturant& operator=(Resturant&& other) noexcept;
    ~Resturant();
    void showMenu() const;
    Customer* getCustomerByName(const std::string& name);
    std::vector<Customer*>& getCustomers();
    void addCustomer(Customer* customer);
    Menu& getMenu();

    void placeNewOrder(const std::string& customerName);
    void viewCustomerOrderHistory(const std::string& customerName) const;
}; 

#endif

