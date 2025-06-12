# Unique Number of Occurrences

## Problem Description
Determine if the number of occurrences of each value in an array is unique.

### Solution Approach
- Count frequency of each element
- Check if frequencies are unique
- Use vectors for tracking

### Time & Space Complexity
- Time: O(n²) for checking unique frequencies
- Space: O(n) for frequency storage

### Building and Testing
```bash
g++ UniqueNumberOfOccurences.cpp main.cpp
./a.out
```

### Test Cases
- True case: [1,2,2,1,1,3] → true (1→3, 2→2, 3→1)
- False case: [1,2,2,1,1,3,3] → false (1→3, 2→2, 3→2)
- Single: [1] → true