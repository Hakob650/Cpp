#include <iostream>
#include "IsomorphicStrings.hpp"

int main() {
    Solution sol;
    
    std::string s[] = {"egg", "foo", "paper", "badc"};
    std::string t[] = {"add", "bar", "title", "baba"};

    int size = sizeof(s) / sizeof(s[0]);

    for (int i = 0; i < size; ++i) {
        bool result = sol.isIsomorphic(s[i], t[i]);
        std::cout << "\"" << s[i] << "\" and \"" << t[i] 
                  << "\" are " << (result ? "" : "not ") << "isomorphic\n";
    }

    return 0;
}
