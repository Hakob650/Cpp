# E-HealthCare Management System

> A C++ console application to manage doctors, patients, medical histories, and generate medical reports. 
> Designed with modular architecture, enum classes for safety, and unit-tested using Google Test.

---
## Features
-  **Doctor Registration**: Name, specialization, years of experience, contact info 
- **Patient Registration**: Name, date of birth, gender, contact, medical conditions 
- **Medical History**: Record diagnoses, treatments, medications per patient 
- **Report Generation**: Print full medical history report on console 
- **Report Saving**: Save report as `PatientName_YYYY-MM-DD.txt` 
- **Search Patients** by name 
- **Enum classes** for strong typing (Gender, Specialization) 
- **Unit Tested** with Google Test 
- **File-based persistent storage** (no database required)
---

## Project Structure
EHealthCareSystem/
├── src/ # Source files (.cpp and .hpp)
│ ├── main.cpp
│ ├── doctor.cpp / .hpp
│ ├── patient.cpp / .hpp
│ ├── manager.cpp / .hpp
│ ├── medical.cpp / .hpp
│ ├── person.cpp / .hpp
│ └── enums.cpp / .hpp
├── tests/ # Google Test files
│ └── test_healthcare.cpp
├── build/ # Object files (auto-generated)
├── Makefile
└── README.md

## Build Instructions
### Prerequisites
- C++17-compatible compiler (e.g., `g++`, `clang++`) 
- `make` build tool 
- [Google Test](https://github.com/google/googletest) (must be built manually if not pre-installed)
### Build the Application
```bash
make
```
### Run Unit Tests
```bash
  make run_test
```

### Running the Program
  ## Start the app:
      ```bash
      ./EHealthCareSystem
      ```

You will see a simple menu allowing you to:
Register doctors and patients
Add medical history records
Generate and save reports

Example Console Interaction

Welcome to E-HealthCare Management System
1. Register Doctor
2. Register Patient
3. Add Medical History to Patient
4. Generate Patient Report
5. Exit

Enter your choice: 1

Enter Doctor Name: Dr. Anna Smith

Enter Specialization: Cardiologist

Enter Years of Experience: 15

Enter Contact Info: anna@hospital.com

Doctor registered successfully!

---
Enter your choice: 2

Enter Patient Name: John Doe

Enter Date of Birth (YYYY-MM-DD): 1985-04-12

Enter Gender (Male/Female): Male

Enter Contact Info: john.doe@mail.com

Enter Existing Medical Conditions: Hypertension

Patient registered successfully!

---

Enter your choice: 3

Enter Patient Name: John Doe

Enter Diagnosis: High blood pressure

Enter Treatment: Lifestyle change, medication

Enter Medication: Lisinopril

Enter Date (YYYY-MM-DD): 2025-06-24

Medical history added successfully!

---

Enter your choice: 4

Enter Patient Name: John Doe

--- Medical Report ---
Name: John Doe

DOB: 1985-04-12

Gender: Male

Contact: john.doe@mail.com

Conditions: Hypertension

Medical History:

Date: 2025-06-24

Diagnosis: High blood pressure

Treatment: Lifestyle change, medication

Medication: Lisinopril

Report saved as John_Doe_2025-06-24.txt

Cleaning Build Files
  ```bash
  make clean
  ```

License
  Educational use only. Contributions and forks welcome.



