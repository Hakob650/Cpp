#include "GuessNumberHigherOrLower.hpp"

int picked = 6;  // Global variable for testing

int Solution::guessNumber(int num) {
    int l = 0, h = num;
    while(l <= h) {
        int m = l + (h - l) / 2;
        int res = guess(m);
        
        if(res == 0) {
            return m;
        }
        else if(res < 0) {
            h = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return -1;
}

int guess(int num) {
    if(num > picked) {
        return -1;
    }
    if(num < picked) {
        return 1;
    }
    return 0;
}
