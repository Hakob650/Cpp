#ifndef DISH_HPP
#define DISH_HPP

#include <string>

class Dish {
private:
    std::string name;
    double price;
public:
    Dish();
    Dish(std::string name, double price);
    Dish(const Dish& other);
    Dish& operator=(const Dish& other);
    Dish(Dish&& other) noexcept;
    Dish& operator=(Dish&& other) noexcept;

    virtual ~Dish() = default;
    virtual void display() const;

    double getPrice() const;
    std::string getName() const;
};

#endif