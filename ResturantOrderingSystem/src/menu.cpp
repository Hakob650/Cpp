#include "../include/menu.hpp"
#include "../include/dish.hpp"

Menu::Menu(const Menu& other)
{
    for(const Dish* dish : other.dishes)
    {
        dishes.push_back(new Dish(*dish));
    }
}

Menu& Menu::operator=(const Menu& other)
{
    if(this != &other)
    {
        for(Dish* dish : other.dishes)
        {
            delete dish;
        }
        dishes.clear();
        for(const Dish* dish : other.dishes)
        {
            dishes.push_back(new Dish(*dish));
        }
    }
    return *this;
}

Menu::Menu(Menu&& other) noexcept
    : dishes(std::move(other.dishes))
    {
        other.dishes.clear();
    }

Menu& Menu::operator=(Menu&& other) noexcept
{
    if(this != &other)
    {
        for(Dish* dish : other.dishes)
        {
            delete dish;
        }
    }
    dishes = std::move(other.dishes);
    other.dishes.clear();
    return *this;
}

Menu::~Menu()
{
    for(Dish* dish : dishes)
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
    for(const Dish* dish : dishes)
    {
        dish->display();
    }
}

Dish* Menu::getDishbyName(const std::string& dishName) const
{
    for(Dish* dish : dishes)
    {
        if(dish->getName() == dishName)
        {
            return dish;
        }
    }
    return nullptr;
}