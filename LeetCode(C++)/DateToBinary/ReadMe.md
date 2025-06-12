# Convert Date to Binary

## Problem Description
Convert a date string to its binary representation.

### Solution Approach
- Parse date components (year, month, day)
- Convert each component to binary
- Concatenate with spaces

### Time & Space Complexity
- Time: O(log n) for each component
- Space: O(1) - fixed size outputs

### Testing
``` bash
g++ main.cpp DateToBinary.cpp
./a.out
```

### Test Cases
- Basic: "2023-10-05"
- Edge: "2000-01-01"
- Max: "9999-12-31"
