class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        # Initialize min_dist with a large value
        min_dist = float('inf')
        
        for i, num in enumerate(nums):
            # Check if the current element matches our target
            if num == target:
                # Update min_dist if the current absolute difference is smaller
                current_dist = abs(i - start)
                if current_dist < min_dist:
                    min_dist = current_dist
                
                # Optimization: if we find a distance of 0, we can't do better
                if min_dist == 0:
                    return 0
                    
        return min_dist