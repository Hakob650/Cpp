#include <iostream>
#include "../include/SystemManager.hpp"

void HealthCareSystemManager::registerDoctor(const Doctor& d)
{
    doctors.push_back(d);
}

void HealthCareSystemManager::registerPatient(const Patient& p)
{
    patients.push_back(p);
}

void HealthCareSystemManager::listDoctors() const
{
    for(size_t i = 0; i < doctors.size(); ++i)
    {
        doctors[i].displayInfo();
    }
}

void HealthCareSystemManager::listPatient() const
{
    for(size_t  i = 0; i < patients.size(); ++i)
    {
        patients[i].displayInfo();
    }
}

int HealthCareSystemManager::findPatientIndexByName(const std::string& name)
{
    for(size_t i = 0; i < patients.size(); ++i)
    {
        if(patients[i].getName() == name)
        {
            return static_cast<int>(i);
        }
    }
    return 0;
}

const std::vector<Doctor>& HealthCareSystemManager::getDoctors() const
{
    return doctors;
}

const std::vector<Patient>& HealthCareSystemManager::getPatients() const
{
    return patients;
}

std::vector<Patient>& HealthCareSystemManager::getPatients()
{
    return patients;
}