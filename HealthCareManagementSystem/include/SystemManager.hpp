#pragma once

#include <vector>
#include "Doctor.hpp"
#include "Patient.hpp"

class HealthCareSystemManager
{
public:
        void registerDoctor(const Doctor& d);
        void registerPatient(const Patient& p);
        void listDoctors() const;
        void listPatient() const;
        int findPatientIndexByName(const std::string& name);
        const std::vector<Doctor>& getDoctors() const;
        const std::vector<Patient>& getPatients() const;
        std::vector<Patient>& getPatients();
        

private:
        std::vector<Doctor> doctors;
        std::vector<Patient> patients;
};