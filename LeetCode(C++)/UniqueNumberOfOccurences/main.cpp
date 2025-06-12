#include <iostream>
#include "UniqueNumberOfOccurences.hpp"

int main() {
    Solution sol;

    std::vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    std::cout << "Test case 1 result: " << std::boolalpha 
              << sol.uniqueOccurrences(arr1) << std::endl;

    std::vector<int> arr2 = {1, 1, 2, 2, 2, 3};
    std::cout << "Test case 2 result: " << std::boolalpha 
              << sol.uniqueOccurrences(arr2) << std::endl;
  
    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    std::cout << "Test case 3 result: " << std::boolalpha 
              << sol.uniqueOccurrences(arr3) << std::endl;

    std::vector<int> arr4 = {1, 1, 1, 1};
    std::cout << "Test case 4 result: " << std::boolalpha 
              << sol.uniqueOccurrences(arr4) << std::endl;

    return 0;
}
