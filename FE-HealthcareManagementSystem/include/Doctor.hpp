#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include "Person.hpp"

class Doctor : public Person
{
private:
        std::string specialization;
        int yoe;
public:
        void inputDetails() override;
        void DisplayDetails() const override;
};

#endif