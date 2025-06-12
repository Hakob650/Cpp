#include "UniqueNumberOfOccurences.hpp"
#include <algorithm>

bool Solution::uniqueOccurrences(std::vector<int>& arr) {
    std::vector<int> freq;
    std::vector<int> unique_freq;

    for (int i = 0; i < arr.size(); ++i) {
        int count = 0;
        for (int j = 0; j < arr.size(); ++j) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

       if (std::find(freq.begin(), freq.end(), arr[i]) == freq.end()) {
            freq.push_back(arr[i]);
            unique_freq.push_back(count);
        }
    }

   for (int i = 0; i < unique_freq.size(); ++i) {
        for (int j = i + 1; j < unique_freq.size(); ++j) {
            if (unique_freq[i] == unique_freq[j]) {
                return false;  
            }
        }
    }
    return true;  
}
