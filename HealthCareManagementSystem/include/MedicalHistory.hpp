#ifndef MEDICALHISTORY_HPP
#define MEDICALHISTORY_HPP

#include <string>

struct Medical
{
    std::string diagnosis;
    std::string treatment;
    std::string medications;
    std::string date;

    void display() const;
};

#endif
