#include <vector>
#include <string>
#include "customer.hpp"
#include "menu.hpp"

#ifndef RESTURANT_HPP
#define RESTURANT_HPP

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
    Menu& getMenu();

    void placeNewOrder(const std::string& customerName);
    void viewCustomerOrderHistory(const std::string& customerName) const;
}; 

#endif
