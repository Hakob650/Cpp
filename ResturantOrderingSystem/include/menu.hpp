#include <vector>
#include <string>
#include "dish.hpp"

#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
private:
        std::vector <Dish*> dishes;
public:
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
