#include <iostream>
#include "../include/Menu.hpp"


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
    for (Dish* dish : dishes) 
    {
        delete dish;
    }
}

void Menu::addDish(Dish* dish)
{
    dishes.push_back(dish);
}

void Menu::displayMenu() const 
{
    for (const Dish* dish : dishes) 
    {
        dish->display();
    }
}

Dish* Menu::getDishbyName(const std::string& dishName) const 
{
    for (Dish* dish : dishes) 
    {
        if (dish->getName() == dishName) 
        {
            return dish;
        }
    }
    return nullptr;
}