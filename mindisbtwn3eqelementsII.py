from typing import List

class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        # Dictionary to store the last two seen indices for each number
        # pos[num] = [index_of_first_occurrence, index_of_second_occurrence]
        pos = {}
        min_dist = float('inf')
        
        for curr_idx, val in enumerate(nums):
            if val in pos:
                indices = pos[val]
                
                # If we've seen this value twice before, we now have a triplet
                if len(indices) == 2:
                    first_idx = indices[0]
                    # Distance is 2 * (current_index - first_index_of_triplet)
                    current_dist = 2 * (curr_idx - first_idx)
                    if current_dist < min_dist:
                        min_dist = current_dist
                    
                    # Update the window: slide it forward
                    # The second index becomes the new 'first', current becomes 'second'
                    pos[val] = [indices[1], curr_idx]
                else:
                    # We've seen it once, now we have two indices
                    indices.append(curr_idx)
            else:
                # First time seeing this number
                pos[val] = [curr_idx]
        
        return min_dist if min_dist != float('inf') else -1