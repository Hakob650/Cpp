# Two Sneaky Numbers

## Problem Description
Find all numbers that appear exactly twice in an array. These numbers are called "sneaky" because they hide by appearing multiple times.

### Solution Approach
- Use frequency counting array to track occurrences
- Single pass through array to count frequencies
- Return numbers that occur exactly twice


### Time & Space Complexity
- Time: O(n) - single pass through array
- Space: O(n) - for frequency counting array

### Building and Testing
```bash
g++  TwoSneakyNumbers.cpp main.cpp
./a.out
```

### Example
```
Input: [7,1,5,4,3,4,6,0,9,5,8,2]
Output: [4,5]
Explanation: Numbers 4 and 5 appear exactly twice
```

### Test Cases
- Basic case: [1,2,2,1] → [1,2]
- No doubles: [1,2,3] → []
- All doubles: [1,1,2,2] → [1,2]
- Mixed case: [1,2,2,3,1] → [1,2]
