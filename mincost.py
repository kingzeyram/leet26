from typing import List

class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        """
        Logic:
        1. The first subarray MUST start at index 0, so nums[0] is always a cost.
        2. We need to find two more 'starts' for the remaining two subarrays.
        3. To minimize the sum, we find the two smallest values in nums[1:].
        """
        
        # The first element is unavoidable
        total_cost = nums[0]
        
        # Initialize the two smallest values as infinity
        min1 = float('inf')
        min2 = float('inf')
        
        # Iterate through the rest of the array once - O(n)
        for i in range(1, len(nums)):
            val = nums[i]
            if val < min1:
                # Update second smallest before updating the smallest
                min2 = min1
                min1 = val
            elif val < min2:
                # Update only the second smallest
                min2 = val
                
        return total_cost + min1 + min2

# Example Usage:
# sol = Solution()
# print(sol.minimumCost([10, 3, 1, 1])) # Output: 12