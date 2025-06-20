#include <iostream>
#include "../include/order.hpp"
#include "../include/customer.hpp"

Order::Order(Customer* customer)
    : customer(customer), totalPrice(0.0) {}

Order::Order(const Order& other)
    : customer(other.customer), totalPrice(other.totalPrice)
    {
        orderedDishes = other.orderedDishes;
    }

Order& Order::operator=(const Order& other)
{
    if(this != &other)
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
    if(this != &other)
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
    for(const Dish* dish : orderedDishes)
    {
        totalPrice += dish->getPrice();
    }
}

void Order::displayOrder() const
{
    std::cout << "Customer: ";
    if(customer)
    {
        std::cout << customer->getName();
    } 
    else
    {
        std::cout << "Unknown";
    }

    std::cout << "Ordered Dishes:\n";
    for(const Dish* dish : orderedDishes)
    {
        if(dish)
        {
            dish->display();
        }
    }

    std::cout << "Total Price: $" << totalPrice << "\n";
}