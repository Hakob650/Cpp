#include <iostream>
#include "DifferenceOfTwoArrays.hpp"

int main() {
    Solution sol;
    std::vector<int> nums1 = {1,2,3};
    std::vector<int> nums2 = {2,4,6};
    std::vector<int> nums3 = {1,2,3,3};
    std::vector<int> nums4 = {1,1,2,2};

    std::vector<std::vector<int>> result1 = sol.findDifference(nums1, nums2);
    std::vector<std::vector<int>> result2 = sol.findDifference(nums3, nums4);

    std::cout << "Difference between nums1 and nums2: ";
    for(int i = 0; i < result1[0].size(); ++i) {
        std::cout << result1[0][i] << " ";
    }
    std::cout << "\n";

    std::cout << "Difference between nums2 and nums1: ";
    for(int i = 0; i < result1[1].size(); ++i) {
        std::cout << result1[1][i] << " ";
    }
    std::cout << "\n";

    std::cout << "Difference between nums3 and nums4: ";
    for(int i = 0; i < result2[0].size(); ++i) {
        std::cout << result2[0][i] << " ";
    }
    std::cout << "\n";

    std::cout << "Difference between nums4 and nums3: ";
    for(int i = 0; i < result2[1].size(); ++i) {
        std::cout << result2[1][i] << " ";
    }
    std::cout << "\n";

    return 0;
}
