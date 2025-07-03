#ifndef ORDER_HPP
#define ORDER_HPP

#include "Dishes.hpp"
#include <vector>

class Customer;  

class Order 
{
private:
    Customer* customer;
    std::vector<Dish*> orderedDishes;
    double totalPrice;
public:
    Order() = default;
    Order(Customer* customer);
    Order(const Order& other);
    Order& operator=(const Order& other);
    Order(Order&& other) noexcept;
    Order& operator=(Order&& other) noexcept;
    ~Order() = default;

    void addDish(Dish* dish);
    void calculateTotal();
    void displayOrder() const;
    std::string getCustomerName() const;

};

#endif
