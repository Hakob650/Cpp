#include <iostream>
#include "include/restaurant.hpp"

Restaurant::Restaurant() {};

Restaurant::Restaurant(const Restaurant& other)
    : menu(other.menu), customers(other.customers), orders(other.orders) {}

Restaurant& Restaurant::operator=(const Restaurant& other)
{
    if(this != &other)
    {
        menu = other.menu;
        customers = other.customers;
        orders = other.orders;
    }
    return *this;
}

Restaurant::Restaurant(Restaurant&& other) noexcept
    : menu(std::move(other.menu)), customers(std::move(other.customers)), orders(std::move(other.orders)) {}

Restaurant& Restaurant::operator=(Restaurant&& other) noexcept
{
    if(this != &other)
    {
        menu = std::move(other.menu);
        customers = std::move(other.customers);
        orders = std::move(other.orders);
    }
    return *this;
}

Restaurant::~Restaurant()
{
    for(Customer* customer : customers)
    {
        delete customer;
    }    
}

void Restaurant::showMenu() const
{
    menu.displayMenu();
}

Customer* Restaurant::getCustomerByName(const std::string& name)
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

void Restaurant::placeNewOrder(const std::string& customerName)
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

void Restaurant::viewCustomerOrderHistory(const std::string& customerName) const
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

Menu& Restaurant::getMenu()
{
    return menu;
}

std::vector<Customer*>& Restaurant::getCustomers()
{
    return customers;
}