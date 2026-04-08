from typing import List

class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        MOD = 10**9 + 7
        
        # Process each query sequentially
        for li, ri, ki, vi in queries:
            # Update every ki-th element from li to ri
            for idx in range(li, ri + 1, ki):
                nums[idx] = (nums[idx] * vi) % MOD
        
        # Calculate the bitwise XOR of all elements in the modified array
        ans = 0
        for x in nums:
            ans ^= x
            
        return ans