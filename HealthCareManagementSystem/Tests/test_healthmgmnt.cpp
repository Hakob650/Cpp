#include <gtest/gtest.h>
#include "include/Doctor.hpp"
#include "include/Patient.hpp"
#include "include/SystemManager.hpp"
#include "include/MedicalHistory.hpp"

TEST(DoctorTest, Tests)
{
    Doctor d("Name", "1980-01-01","example@gmail.com",Gender::FEMALE,Specialization::SURGEON,20);
    EXPECT_EQ(d.getName(), "Name");
}

TEST(PatientTest, AddHistory)
{
    Patient p("Name", "1995-12-12", "example@gmail.com", Gender::MALE, "Asthma");
    p.addHistory({"Diagnosis", "Treatment", "Medication", "2025-06-23"});
    SUCCEED();
}

TEST(SystemTest, RegisterFindPatient)
{
    HealthCareSystemManager mgr;
    Patient p("Name", "2000-01-01", "example@gmail.com", Gender::FEMALE, "None");
    mgr.registerPatient(p);

    int index = mgr.findPatientIndexByName("Name");
    ASSERT_NE(index, -1);
    EXPECT_EQ(mgr.getPatients()[index].getName(), "Name");
}
