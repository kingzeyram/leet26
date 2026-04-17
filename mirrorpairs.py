from typing import List

class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        # Helper to reverse digits (e.g., 120 -> 21)
        def get_reverse(n: int) -> int:
            res = 0
            while n > 0:
                res = res * 10 + (n % 10)
                n //= 10
            return res

        # key: the value that a future index j must have
        # value: the index i where that requirement was created
        last_seen_target = {}
        min_dist = float('inf')
        
        for idx, val in enumerate(nums):
            # Check if current value matches a target set by a previous index
            if val in last_seen_target:
                min_dist = min(min_dist, idx - last_seen_target[val])
            
            # Set a target for future indices based on current value
            # reverse(nums[i]) == nums[j]
            target = get_reverse(val)
            
            # We update the target with the current index. 
            # If the same target exists, we want the largest index (idx)
            # to minimize the distance for future matches.
            last_seen_target[target] = idx
            
        return min_dist if min_dist != float('inf') else -1