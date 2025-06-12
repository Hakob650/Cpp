#include <iostream>
#include <vector>
#include "MinimumCommonValue.hpp"

int main()
{
    Solution sol;
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {5, 6, 7, 8, 9};

    int commonValue = sol.getCommon(nums1, nums2);
    if (commonValue != -1)
    {
        std::cout << "Common value: " << commonValue << std::endl;
    }
    else
    {
        std::cout << "No common value found." << std::endl;
    }

    return 0;
}
