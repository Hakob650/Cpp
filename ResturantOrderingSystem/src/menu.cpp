#include "../include/menu.hpp"
#include <iostream>

Menu::Menu() {}

Menu::Menu(const Menu& other) : dishes(other.dishes) {}

Menu& Menu::operator=(const Menu& other) 
{
    if (this != &other) 
    {
        dishes = other.dishes;
    }
    return *this;
}

Menu::Menu(Menu&& other) noexcept : dishes(std::move(other.dishes)) {}

Menu& Menu::operator=(Menu&& other) noexcept 
{
    if (this != &other) 
    {
        dishes = std::move(other.dishes);
    }
    return *this;
}

Menu::~Menu() 
{
    for (size_t i = 0; i < dishes.size(); ++i)
    {
        delete dishes[i];
    }
}

void Menu::addDish(Dish* dish)
{
    dishes.push_back(dish);
}

void Menu::displayMenu() const 
{
    for (size_t i = 0; i < dishes.size(); ++i)
    {
        dishes[i]->display();
    }
}

Dish* Menu::getDishbyName(const std::string& dishName) const 
{
  for (size_t i = 0; i < dishes.size(); ++i)
    {
        if (dishes[i]->getName() == dishName)
        {
            return dishes[i];
        }
    }
}
