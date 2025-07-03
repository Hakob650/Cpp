#ifndef MENU_HPP
#define MENU_HPP

#include "Dishes.hpp"
#include <vector>
#include <string>

class Menu 
{
private:
    std::vector<Dish*> dishes;
public:
    Menu();
    Menu(const Menu& other);
    Menu& operator=(const Menu& other);
    Menu(Menu&& other) noexcept;
    Menu& operator=(Menu&& other) noexcept;
    ~Menu();

    void addDish(Dish* dish);
    void displayMenu() const;
    Dish* getDishbyName(const std::string& dishName) const;
};

#endif