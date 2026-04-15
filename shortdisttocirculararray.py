class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        n = len(words)
        min_dist = float('inf')
        
        for i in range(n):
            if words[i] == target:
                # Calculate the absolute difference between indices
                abs_diff = abs(i - startIndex)
                
                # The shortest distance to this specific index i is the 
                # minimum of moving directly or wrapping around the circle.
                current_dist = min(abs_diff, n - abs_diff)
                
                # Update the global minimum
                min_dist = min(min_dist, current_dist)
        
        return min_dist if min_dist != float('inf') else -1