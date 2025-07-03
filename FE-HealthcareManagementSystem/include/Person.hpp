#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>

class Person
{
protected:
            std::string name;
            std::string contact;
public:
            virtual void inputDetails();
            virtual void DisplayDetails() const;
            std::string getName() const;
};

#endif