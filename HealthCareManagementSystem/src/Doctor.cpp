#include "../include/Doctor.hpp"
#include <iostream>
Doctor::Doctor(std::string name, std::string dob, std::string contact,
        Gender gender,Specialization spec, int experience)
    : Person(name, dob, contact, gender), specialization(spec), experience(experience) {}

void Doctor::displayInfo() const 
{
    std::cout << "Doctor: " << name
              << ", Specialization: " << specializationToString(specialization)
              << ", Experience: " << experience << " years"
              << ", Contact: " << contact << std::endl;
}




