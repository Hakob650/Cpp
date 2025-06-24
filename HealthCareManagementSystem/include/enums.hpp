#ifndef ENUMS_HPP
#define ENUMS_HPP

#include <string>

enum class Gender { MALE, FEMALE};
enum class Specialization { CARDIOLOGIST, NEUROLOGIST, GENERALPHYSICIAN, SURGEON, PEDIATRICIAN, ONCOLOGIST};

std::string genderToString(Gender g);
std::string specializationToString(Specialization s);

#endif