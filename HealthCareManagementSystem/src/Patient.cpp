#include "../include/Patient.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
Patient::Patient(std::string name, std::string dob, 
                 std::string contact, Gender gender, std::string conditions)
    : Person(name, dob, contact, gender), conditions(conditions) {}

    
void Patient::addHistory(const Medical& m) 
{
    history.push_back(m);
}
void Patient::displayInfo() const 
{
    std::cout << "Patient: " << name << ", DOB: " << dob
              << ", Gender: " << genderToString(gender)
              << ", Contact: " << contact
              << ", Conditions: " << conditions << std::endl;
}

void Patient::generateReport() const 
{
    std::cout << "\n=== Report for " << name << " ===\n";
    displayInfo();
    std::cout << "\nMedical History:\n";
    for (size_t i = 0; i < history.size(); ++i)
      {
        history[i].display();
      }
}

void Patient::saveReporttoFile() const 
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    std::string filename = name + "_" + std::to_string(1900 + ltm->tm_year) + "-" +
                           std::to_string(1 + ltm->tm_mon) + "-" + std::to_string(ltm->tm_mday) + ".txt";
    std::ofstream out(filename);
    if (out) 
    {
        out << "Medical Report for " << name << "\n";
        out << "DOB: " << dob << ", Gender: " << genderToString(gender)
            << ", Contact: " << contact << "\n";
        out << "Conditions: " << conditions << "\n\n";
      for (size_t i = 0; i < history.size(); ++i) 
      {
            out << "Date: " << history[i].date << "\nDiagnosis: " << record.diagnosis
                << "\nTreatment: " << history[i].treatment
                << "\nMedications: " <<history[i].medications << "\n\n";
        }
        out.close();
        std::cout << "Saved to: " << filename << std::endl;
    } 
    else 
    {
        std::cerr << "File error.\n";
    }
}






