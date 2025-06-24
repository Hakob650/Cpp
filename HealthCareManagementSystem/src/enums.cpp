#include "../include/enums.hpp"

std::string genderToString(Gender g)
{
    switch(g)
    {
        case Gender::MALE: return "Male";
        case Gender::FEMALE: return "Female";
    }
    return "Unknown";
}

std::string specializationToString(Specialization s)
{
    switch(s)
    {
        case Specialization::CARDIOLOGIST: return "Cardiologist";
        case Specialization::NEUROLOGIST: return "Neurologist";
        case Specialization::GENERALPHYSICIAN: return "General Physician";
        case Specialization::SURGEON: return "Surgeon";
        case Specialization::PEDIATRICIAN: return "Pediatrician";
        case Specialization::ONCOLOGIST: return "Oncologist";
    }
    return "Unknown";
}

