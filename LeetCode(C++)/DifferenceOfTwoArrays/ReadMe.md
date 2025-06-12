# Difference of Two Arrays

## Problem Description
Find elements that exist in one array but not in the other.

### Solution Approach
- Compare each element of first array with second
- Track unique differences in separate vectors
- Handle duplicates carefully

### Time & Space Complexity
- Time: O(n*m) where n,m are array lengths
- Space: O(n+m) for result vectors

### Building and Testing
```bash
g++ DifferenceOfTwoArrays.cpp main.cpp -o diff
./a.out
```

### Test Cases
- Basic: [1,2,3], [2,4,6] → [[1,3],[4,6]]
- No diff: [1,2], [1,2] → [[],[]]
- All diff: [1,2], [3,4] → [[1,2],[3,4]]