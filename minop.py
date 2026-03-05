# You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

# The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

# Return the minimum number of operations needed to make s alternating.

 

# Example 1:

# Input: s = "0100"
# Output: 1
# Explanation: If you change the last character to '1', s will be "0101", which is alternating.
# Example 2:

# Input: s = "10"
# Output: 0
# Explanation: s is already alternating.
# Example 3:

# Input: s = "1111"
# Output: 2
# Explanation: You need two operations to reach "0101" or "1010".
 

# Constraints:

# 1 <= s.length <= 104
# s[i] is either '0' or '1'.

class Solution:
    def minOperations(self, s: str) -> int:
        count0 = 0  # Operations needed to make string match "0101..."
        n = len(s)
        
        for i in range(n):
            # For the pattern "010101...", 
            # indices 0, 2, 4 should be '0'
            # indices 1, 3, 5 should be '1'
            if i % 2 == 0:
                if s[i] != '0':
                    count0 += 1
            else:
                if s[i] != '1':
                    count0 += 1
        
        # The number of operations for the "101010..." pattern 
        # is simply the total length minus count0.
        return min(count0, n - count0)