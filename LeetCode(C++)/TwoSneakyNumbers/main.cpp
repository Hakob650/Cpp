#include <iostream>
#include "TwoSneakyNumbers.hpp"

int main() {
    Solution sol;
    std::vector<int> nums = {7,1,5,4,3,4,6,0,9,5,8,2};
    std::vector<int> sneakyNumbers = sol.getSneakyNumbers(nums);
    
    std::cout << "Sneaky numbers: ";
    for(int i = 0; i < sneakyNumbers.size(); ++i) {
      int num = sneakyNumbers[i];  
      std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
