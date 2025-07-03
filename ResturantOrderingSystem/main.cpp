#include <iostream>
#include "include/Resturant.hpp"
#include "include/Appetizers.hpp"


int main() {
    Resturant resturant;

    
    resturant.getMenu().addDish(new Appetizer("Spring Rolls", 5.99, false));
    resturant.getMenu().addDish(new Entree("Pizza", 12.99, 800));
    resturant.getMenu().addDish(new Dessert("Ice Cream", 4.99, false));

    std::string customerName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, customerName);

    Customer* customer = resturant.getCustomerByName(customerName);
    if (!customer) {
        customer = new Customer(customerName, "N/A");
        resturant.getCustomers().push_back(customer);
    }

    resturant.placeNewOrder(customerName);
    resturant.viewCustomerOrderHistory(customerName);

    return 0;
}