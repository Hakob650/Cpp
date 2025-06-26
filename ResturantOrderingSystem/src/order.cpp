#include "../include/order.hpp"
#include "../include/customer.hpp"
#include <iostream>

Order::Order(Customer* customer) : customer(customer), totalPrice(0.0) {}

Order::Order(const Order& other)
    : customer(other.customer), orderedDishes(other.orderedDishes), totalPrice(other.totalPrice) {}

Order& Order::operator=(const Order& other) 
{
    if (this != &other) 
    {
        customer = other.customer;
        orderedDishes = other.orderedDishes;
        totalPrice = other.totalPrice;
    }
    return *this;
}

Order::Order(Order&& other) noexcept
    : customer(other.customer), orderedDishes(std::move(other.orderedDishes)), totalPrice(other.totalPrice) 
{
    other.customer = nullptr;
    other.totalPrice = 0.0;
}

Order& Order::operator=(Order&& other) noexcept 
{
    if (this != &other) 
    {
        customer = other.customer;
        orderedDishes = std::move(other.orderedDishes);
        totalPrice = other.totalPrice;
        other.customer = nullptr;
        other.totalPrice = 0.0;
    }
    return *this;
}

void Order::addDish(Dish* dish) 
{
    orderedDishes.push_back(dish);
}

void Order::calculateTotal() 
{
    totalPrice = 0.0;
    
    for (size_t i = 0; i < orderedDishes.size(); ++i)
    {
        totalPrice += orderedDishes[i]->getPrice();
    }
}

void Order::displayOrder() const 
{
    std::cout << "Customer: " << (customer ? customer->getName() : "Unknown") << "\n";
    std::cout << "Ordered Dishes:\n";
    for (size_t i = 0; i < orderedDishes.size(); ++i)
    {
        if (orderedDishes[i])
        {
            orderedDishes[i]->display();
        }
    }
    std::cout << "Total Price: $" << totalPrice << "\n";
}
