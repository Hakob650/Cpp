#include "../include/customer.hpp"


Customer::Customer(std::string customerName,std::string contact)
    : name(customerName), contactInfo(contact) {}

Customer::Customer(const Customer& other)
    : name(other.name), contactInfo(other.contactInfo) {}

Customer& Customer::operator=(const Customer& other)
{
    if(this != &other)
    {
        name = other.name;
        contactInfo = other.contactInfo;
    }
    return *this;
}

Customer::Customer(Customer&& other) noexcept
    : name(std::move(other.name)), contactInfo(std::move(other.contactInfo)) {}

Customer& Customer::operator=(Customer&& other) noexcept
{
    if(this != &other)
    {
        name = std::move(other.name);
        contactInfo = std::move(other.contactInfo);

        other.name = " ";
        other.contactInfo = " ";
    }
    return *this;
}

void Customer::placeOrder(Order order)
{
    orderHistory.push_back(order);
}

void Customer::viewOrderHistory() const
{
    for(const auto& order : orderHistory)
    {
        order.displayOrder();
    }
}

std::string Customer::getName() const
{
    return name;
}