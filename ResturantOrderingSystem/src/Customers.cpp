#include <iostream>
#include "../include/Customers.hpp"

Customer::Customer(std::string name, std::string contact)
    : name(name), contactInfo(contact) {}

Customer::Customer(const Customer& other)
    : name(other.name), contactInfo(other.contactInfo), orderHistory(other.orderHistory) {}

Customer& Customer::operator=(const Customer& other) 
{
    if (this != &other) {
        name = other.name;
        contactInfo = other.contactInfo;
        orderHistory = other.orderHistory;
    }
    return *this;
}

Customer::Customer(Customer&& other) noexcept
    : name(std::move(other.name)), contactInfo(std::move(other.contactInfo)), orderHistory(std::move(other.orderHistory)) {}

Customer& Customer::operator=(Customer&& other) noexcept 
{
    if (this != &other) {
        name = std::move(other.name);
        contactInfo = std::move(other.contactInfo);
        orderHistory = std::move(other.orderHistory);
    }
    return *this;
}

void Customer::placeOrder(Order order) 
{
    orderHistory.push_back(order);
}

void Customer::viewOrderHistory() const
 {
    for (const auto& order : orderHistory) 
    {
        order.displayOrder();
    }
}

std::string Customer::getName() const 
{
    return name;
}