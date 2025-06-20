#include <string>

#ifndef DISH_HPP
#define DISH_HPP

class Dish
{
private:
        std::string name;
        double price;
public:
        Dish();
        Dish(std::string dishName, double dishPrice);

        Dish(const Dish& other);
        Dish& operator=(const Dish& other);
        Dish(Dish&& other) noexcept;
        Dish& operator=(Dish&& other) noexcept;

        void display() const;
        double getPrice() const;
        std::string getName() const;
};

#endif
