#include "IsomorphicStrings.hpp"
#include <vector>

bool Solution::isIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }

    std::vector<int> mapS(128, 0);  
    std::vector<int> mapT(128, 0);  

    for (int i = 0; i < s.length(); ++i) {
       
        if (mapS[s[i]] != mapT[t[i]]) {
            return false;
        }
        
        mapS[s[i]] = i + 1;
        mapT[t[i]] = i + 1;
    }

    return true;
}
