from typing import List
import bisect

class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)
        # Step 1: Map values to their indices
        val_to_indices = {}
        for idx, val in enumerate(nums):
            if val not in val_to_indices:
                val_to_indices[val] = []
            val_to_indices[val].append(idx)
        
        # Step 2: Pre-calculate the result for each unique value
        # This prevents redundant calculations if a query index is repeated 
        # or if multiple queries point to the same value's index.
        memo = {}
        
        ans = []
        for q_idx in queries:
            target_val = nums[q_idx]
            indices = val_to_indices[target_val]
            
            # If the value appears only once, no other index exists
            if len(indices) <= 1:
                ans.append(-1)
                continue
            
            # Use binary search to find the position of the current index in the list
            pos = bisect.bisect_left(indices, q_idx)
            
            # Candidates are the elements to the left and right in the sorted list
            # We use modulo to handle circular wrap-around
            left_neighbor = indices[(pos - 1) % len(indices)]
            right_neighbor = indices[(pos + 1) % len(indices)]
            
            # Distance formula for circular array: min(|i-j|, n - |i-j|)
            def get_dist(i, j):
                diff = abs(i - j)
                return min(diff, n - diff)
            
            min_dist = min(get_dist(q_idx, left_neighbor), get_dist(q_idx, right_neighbor))
            ans.append(min_dist)
            
        return ans