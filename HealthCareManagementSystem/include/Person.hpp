#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include "enums.hpp"


class Person
{
protected:
            std::string name;
            std::string dob;
            std::string contact;
            Gender gender;
public:
            Person(std::string name, std::string dob, std::string contact, Gender gender);
            virtual void displayInfo() const = 0;
            std::string getName() const;
            virtual ~Person() = default;
};

#endif

