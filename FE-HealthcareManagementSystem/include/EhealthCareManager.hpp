#ifndef EHEALTH_CARE_MANAGER_HPP
#define EHEALTH_CARE_MANAGER_HPP

#include "Doctor.hpp"
#include "Patient.hpp"
#include <vector>

class EHealthCareManager
{
private:
        std::vector<Doctor> doctors;
        std::vector<Patient> patient;
public:
        void registerDoctor();
        void registerPatient();
        void addPatientMedicalHistory();
        void generateReport();
};

#endif