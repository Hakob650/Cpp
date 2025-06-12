#include "DateToBinary.hpp"

std::string Solution::toBinary(int num) {
    std::string binary = "";
    while(num > 0) {
        binary = (num & 1 ? "1" : "0") + binary;
        num >>= 1;
    }
    return binary;
}

std::string Solution::dateToBinary(std::string date) {
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    std::string bin_year = toBinary(year);
    std::string bin_month = toBinary(month);
    std::string bin_day = toBinary(day);

    return bin_year + " " + bin_month + " " + bin_day;
}
