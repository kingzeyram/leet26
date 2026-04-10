from collections import defaultdict
from typing import List

class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        # Step 1: Map each number to a list of its indices
        indices_map = defaultdict(list)
        for idx, num in enumerate(nums):
            indices_map[num].append(idx)
            
        min_total_dist = float('inf')
        found_tuple = False
        
        # Step 2: Iterate through each number's indices
        for num in indices_map:
            pos = indices_map[num]
            
            # We need at least 3 occurrences to form a tuple
            if len(pos) >= 3:
                found_tuple = True
                # Check consecutive triplets (i, j, k)
                # The distance is always 2 * (pos[t+2] - pos[t])
                for t in range(len(pos) - 2):
                    current_dist = 2 * (pos[t+2] - pos[t])
                    if current_dist < min_total_dist:
                        min_total_dist = current_dist
                        
        return int(min_total_dist) if found_tuple else -1