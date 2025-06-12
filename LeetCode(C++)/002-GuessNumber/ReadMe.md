# Guess Number Higher or Lower

## Problem Description
Implement a guessing game where you need to find a secret number between 1 and n using binary search.

### Solution Approach
- Binary search implementation
- Uses the `guess(int)` 
- Efficiently narrows down search space by half each time

### Time & Space Complexity
- Time Complexity: O(log n)
- Space Complexity: O(1)


### Building and Testing
```bash
g++ -std=c++11 GuessNumber.cpp main.cpp -o guess
./guess
```

### Example
```
Input: n = 10, picked = 6
Steps: 
1. Guess 5 -> Too low
2. Guess 8 -> Too high
3. Guess 6 -> Found!
Output: 6
```

### Test Cases
- Mid-range: n=10, picked=6
- Edge case: n=1, picked=1
- Large number: n=2^31-1

### `guess(int num)` Guide
`guess(int num)` returns:
- -1: Your guess is too high
- 1: Your guess is too low
- 0: You found the number!
