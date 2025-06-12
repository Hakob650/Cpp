#include <iostream>
#include "GuessNumberHigherOrLower.hpp"

int main() {
    Solution sol;
    int n = 10;
    int res = sol.guessNumber(n);
    
    if(res != -1) {
        std::cout << "The guessed number is: " << res << std::endl;
    }
    else {
        std::cout << "No number found." << std::endl;
    }
    return 0;
}
