#include <iostream>
#include "../include/Resturant.hpp"

Resturant::Resturant() {};

Resturant::Resturant(const Resturant& other)
    : menu(other.menu), customers(other.customers), orders(other.orders) {}

Resturant& Resturant::operator=(const Resturant& other)
{
    if(this != &other)
    {
        menu = other.menu;
        customers = other.customers;
        orders = other.orders;
    }
    return *this;
}

Resturant::Resturant(Resturant&& other) noexcept
    : menu(std::move(other.menu)), customers(std::move(other.customers)), orders(std::move(other.orders)) {}

Resturant& Resturant::operator=(Resturant&& other) noexcept
{
    if(this != &other)
    {
        menu = std::move(other.menu);
        customers = std::move(other.customers);
        orders = std::move(other.orders);
    }
    return *this;
}

Resturant::~Resturant()
{
    for(Customer* customer : customers)
    {
        delete customer;
    }    
}

void Resturant::showMenu() const
{
    menu.displayMenu();
}

Customer* Resturant::getCustomerByName(const std::string& name)
{
    for(Customer* customer : customers)
    {
        if(customer->getName() == name)
        {
            return customer;
        }
    }
    return nullptr;
}

void Resturant::placeNewOrder(const std::string& customerName)
{
    Customer* customer = getCustomerByName(customerName);
    if(!customer)
    {
        std::cout << "Customer not found\n";
        return;
    }

    Order newOrder(customer);
    menu.displayMenu();

    std::string dishName;
    while(true)
    {
        std::cout << "Enter dish name to add(or 'done' to finish): ";
        std::getline(std::cin, dishName);
        if(dishName == "done")
        {
            break;
        }

        Dish* dish = menu.getDishbyName(dishName);
        if(dish)
        {
            newOrder.addDish(dish);
        }
        else
        {
            std::cout << "Dish not found.\n";
        }
    }

    newOrder.calculateTotal();
    customer->placeOrder(newOrder);
    orders.push_back(newOrder);
}

void Resturant::viewCustomerOrderHistory(const std::string& customerName) const
{
    for(Customer* customer : customers)
    {
        if(customer->getName() == customerName)
        {
            customer->viewOrderHistory();
            return;
        }
    }
    std::cout << "Customer not found.\n";
}

std::vector<Customer*>& Resturant::getCustomers()
{
    return customers;
}

Menu& Resturant::getMenu() {
    return menu;
}

void Resturant::addCustomer(Customer* customer)
{
    customers.push_back(customer);
}
