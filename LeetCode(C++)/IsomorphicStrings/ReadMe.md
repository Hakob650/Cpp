# Isomorphic Strings

## Problem Description
Determine if two strings are isomorphic - characters in one string can be replaced to get the other string.

### Solution Approach
- Use two arrays for character mapping
- Track character mappings using position + 1
- Compare mappings for each character pair

### Time & Space Complexity
- Time: O(n) where n is string length
- Space: O(1) - fixed size arrays (128 ASCII chars)

### Building and Testing
```bash
g++ IsomorphicStrings.cpp main.cpp -o iso
./a.out
```
### Test Cases
- Basic: "egg" -> "add" (true)
- Different: "foo" -> "bar" (false)
- Complex: "paper" -> "title" (true)