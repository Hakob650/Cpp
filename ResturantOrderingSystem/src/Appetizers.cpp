#include <iostream>
#include "../include/Appetizers.hpp"


Appetizer::Appetizer(std::string name, double price, bool spicy)
    : Dish(name, price), isSpicy(spicy) {}

void Appetizer::display() const
{
    Dish::display();
    std::cout << (isSpicy ? "Spicy" : "Not Spicy") << " Appetizer\n";
}

Entree::Entree(std::string name, double price, int cal)
    : Dish(name, price), calories(cal) {}

void Entree::display() const 
{
    Dish::display();
    std::cout << "Calories: " << calories << std::endl;
}

Dessert::Dessert(std::string name, double price, bool nuts)
    : Dish(name, price), containsNuts(nuts) {}

void Dessert::display() const 
{
    Dish::display();
    std::cout << (containsNuts ? "Contains Nuts" : "Nut-Free") << " Dessert\n";
}



