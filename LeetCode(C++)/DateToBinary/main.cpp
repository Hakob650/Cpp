#include <iostream>
#include "DateToBinary.hpp"

int main() {
    Solution sol;
    std::string date = "2023-10-05";
    std::string binaryDate = sol.dateToBinary(date);
    std::cout << "Binary representation of date " << date << " is: " << binaryDate << std::endl;
    return 0;
}
