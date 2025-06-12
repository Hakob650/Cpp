#include "DifferenceOfTwoArrays.hpp"

bool Solution::arr_contains(std::vector<int>& arr, int val) {
    for(int i = 0; i < arr.size(); ++i) {
        if(arr[i] == val) {
            return true;
        }
    }
    return false;
}

std::vector<std::vector<int>> Solution::findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> diff1, diff2;
    
    for(int i = 0; i < nums1.size(); ++i) {
        bool found = false;
        for(int j = 0; j < nums2.size(); ++j) {
            if(nums1[i] == nums2[j]) {
                found = true;
                break;
            }
        }
        if(!found && !arr_contains(diff1, nums1[i])) {
            diff1.push_back(nums1[i]);
        }
    }

    for(int j = 0; j < nums2.size(); ++j) {
        bool found = false;
        for(int i = 0; i < nums1.size(); ++i) {
            if(nums2[j] == nums1[i]) {
                found = true;
                break;
            }
        }
        if(!found && !arr_contains(diff2, nums2[j])) {
            diff2.push_back(nums2[j]);
        }
    }

    return {diff1, diff2};
}
