#include <string>
#include <iostream>
#include "../include/dish.hpp"

Dish::Dish()
  : name(" "), price(0.0) {}

Dish::Dish(std::string dishName, double dishPrice)
 : name(dishName), price(dishPrice) {}

Dish::Dish(const Dish& other)
  : name(other.name), price(other.price) {}

Dish& Dish::operator=(const Dish& other)
{
  if(this != &other)
  {
    name = other.name;
    price = other.price;
  }
  return *this;
}

Dish::Dish(Dish&& other) noexcept
  :name(std::move(other.name)), price(other.price)
  {
    other.name = " ";
    other.price = 0.0;
  }

Dish& Dish::operator=(Dish&& other) noexcept
{
    if(this != &other)
    {
      name = std::move(other.name);
      price = other.price;

      other.name = " ";
      other.price = 0.0;
    }
    return *this;
}

void Dish::display() const
{
    std::cout << "Dish: " << name << "Price: $" << price << std::endl;
}

double Dish::getPrice() const
{
  return price;
}

std::string Dish::getName() const
{
  return name;
}
  
