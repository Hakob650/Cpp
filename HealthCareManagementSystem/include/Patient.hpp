#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <vector>
#include "Person.hpp"
#include "MedicalHistory.hpp"

class Patient : public Person
{
public:
        Patient(std::string name, std::string dob, std::string contact, Gender gender, std::string condition);
        void addHistory(const Medical& m);
        void displayInfo() const override;
        void generateReport() const;
        void saveReporttoFile() const;
private:
        std::string conditions;
        std::vector<Medical> history;
};

#endif
