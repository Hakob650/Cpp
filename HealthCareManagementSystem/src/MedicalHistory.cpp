#include <iostream>
#include "../include/MedicalHistory.hpp"
void Medical::display() const 
{
    std::cout << "Date: " << date << "\nDiagnosis: " << diagnosis
              << "\nTreatment: " << treatment
              << "\nMedications: " << medications << "\n";
}