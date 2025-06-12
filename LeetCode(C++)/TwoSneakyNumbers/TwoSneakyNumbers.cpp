#include <iostream>
#include <vector>
#include "TwoSneakyNumbers.hpp"


std::vector<int> Solution::getSneakyNumbers(std::vector<int>& nums) {
    std::vector<int> count(nums.size(), 0);
    std::vector<int> res;
    
    for(int i = 0; i < nums.size(); ++i) {
        count[nums[i]]++;
        if(count[nums[i]] == 2) {
            res.push_back(nums[i]);
        }
    }
    return res;
}
