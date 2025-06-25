#include <iostream>
#include "../include/Doctor.hpp"
#include "../include/Patient.hpp"
#include "../include/SystemManager.hpp"
#include "../include/enums.hpp"

int main() {
    
    HealthCareSystemManager system;

    Doctor doc1("Dr. Alice Smith", "1975-03-22", "123-456-7890", Gender::FEMALE, Specialization::CARDIOLOGIST, 15);
    Doctor doc2("Dr. John Doe", "1980-08-10", "987-654-3210", Gender::MALE, Specialization::SURGEON, 20);
    system.registerDoctor(doc1);
    system.registerDoctor(doc2);

    Patient pat1("Jane Roe", "1990-05-12", "111-222-3333", Gender::FEMALE, "Hypertension");
    Medical record = {"High blood pressure", "Lifestyle change", "Beta blockers", "2025-06-24"};
    pat1.addHistory(record);
    system.registerPatient(pat1);

    std::cout << "\n--- Doctors ---\n";
    system.listDoctors();

    std::cout << "\n--- Patients ---\n";
    system.listPatient();

    std::cout << "\n--- Patient Report ---\n";
    pat1.generateReport();
    pat1.saveReporttoFile();

    return 0;
}

