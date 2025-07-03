#ifndef DISHTYPES_HPP
#define DISHTYPES_HPP

#include "Dishes.hpp"

class Appetizer : public Dish 
{
private:
    bool isSpicy;
public:
    Appetizer(std::string name, double price, bool spicy);
    void display() const override;
};

class Entree : public Dish 
{
private:
    int calories;
public:
    Entree(std::string name, double price, int cal);
    void display() const override;
};

class Dessert : public Dish 
{
private:
    bool containsNuts;
public:
    Dessert(std::string name, double price, bool nuts);
    void display() const override;
};

#endif