#ifndef PATIENT_HPP
#define PATIENT_HPP

#include "Person.hpp"
#include <vector>
#include <string>

class Patient : public Person
{
private:
        std::string dob;
        std::string gender;
        std::string medicalConditions;
        std::vector<std::string> history;
public:
        void inputDetails() override;
        void DisplayDetails() const override;
        void addMedicalReport(const std::string&);
        void displayMedicalReport() const;
        void saveMedicalReportToFile() const;

};

#endif