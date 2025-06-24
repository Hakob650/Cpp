#pragma once

#include "Person.hpp"

class Doctor : public Person
{
public:
        Doctor(std::string name, std::string dob, std::string contact, Gender gender, Specialization spec, int experience);
        void displayInfo() const override;
private:
        Specialization specialization;
        int experience;
};

