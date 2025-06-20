#include <string>
#include <iostream>
#include "../include/dishtypes.hpp"

Appetizer::Appetizer(std::string dishName, double dishPrice, bool spicy)
  : Dish(dishName, dishPrice), isSpicy(spicy) {}

void Appetizer::display() const
{
    Dish::display();
    std::cout << (isSpicy ? "Spicy" : "Not Spicy") << "Appetizer" << std::endl;
}

Entree::Entree(std::string dishName, double dishPrice, int cal)
    : Dish(dishName, dishPrice), calories(cal) {}

void Entree::display() const
{
    Dish::display();
    std::cout << "Calories" << calories << std::endl;
}

Dessert::Dessert(std::string dishName, double dishPrice, bool nuts)
  : Dish(dishName, dishPrice), containsNuts(nuts) {}

void Dessert::display() const
{
    Dish::display();
    std::cout << (containsNuts ? "Contains Nuts" : "Nut-Free") << "Dessert" << std::endl;
}
