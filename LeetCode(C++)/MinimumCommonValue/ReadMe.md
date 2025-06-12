# Minimum Common Value

## Problem Description
Find the minimum value that appears in both input arrays.

### Solution Approach
- Uses two indexes to traverse both sorted arrays
- Returns first common value (which will be minimum since arrays are sorted)
- Returns -1 if no common value exists

### Time & Space Complexity
- Time Complexity: O(min(n,m)) where n and m are lengths of input arrays
- Space Complexity: O(1)



### Building and Testing
```bash
g++ -std=c++11 MinimumCommonValue.cpp main.cpp -o min_common
./min_common
```

### Example
```
Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: 2 is the minimum element common to both arrays.
```

### Test Cases
- Basic case: `[1,2,3]` and `[2,4]` → `2`
- No common: `[1,3,5]` and `[2,4,6]` → `-1`
- Multiple common: `[1,2,3]` and `[1,2,3]` → `1`
