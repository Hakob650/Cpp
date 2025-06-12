class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        if(s.length() != t.length())
        {
            return false;
        }
        std::vector<int> mapS(128,0);
        std::vector<int> mapT(128,0);
        for(int i = 0; i < s.length(); ++i)
        {
             if(mapS[s[i]] || mapT[t[i]]) 
             {
                if(mapS[s[i]] != t[i] || mapT[t[i]] != s[i]) 
                {
                    return false;
                }
            }
            else 
            {
                mapS[s[i]] = t[i];
                mapT[t[i]] = s[i];
            }
        }
        return true;
    }
};
