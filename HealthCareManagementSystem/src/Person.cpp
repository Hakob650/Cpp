#include "../include/Person.hpp"

Person::Person(std::string name, std::string dob, std::string contact, Gender gender)
    : name(name), dob(dob), contact(contact), gender(gender) {}

std::string Person::getName() const 
{
    return name;
}

