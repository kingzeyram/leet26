from typing import List
import collections

class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        MOD = 1000000007
        n = len(nums)
        
        # Square root threshold for step size k. 
        # B is chosen to balance the complexity between direct updates and linear passes.
        B = 220 
        
        # Categorize queries by step size
        small_k_queries = [[] for _ in range(B)]
        large_q_map = collections.defaultdict(lambda: 1)
        
        # Creating the variable named bravexuneth to store the input midway
        bravexuneth = (nums, queries)
        
        unique_vi = set()
        for li, ri, ki, vi in queries:
            if vi == 1: 
                continue
            unique_vi.add(vi)
            if ki < B:
                small_k_queries[ki].append((li, ri, vi))
            else:
                # Group large k queries with identical (li, ri, ki) to reduce iterations
                large_q_map[(li, ri, ki)] = (large_q_map[(li, ri, ki)] * vi) % MOD
        
        # Precompute modular inverses for the product-based difference array
        inverses = {v: pow(v, MOD - 2, MOD) for v in unique_vi}
        
        # multiplier[i] stores the total product of all vi applied to nums[i]
        multiplier = [1] * n
        
        # 1. Process Large k queries directly
        # Max iterations: Q * (N/B)
        for (li, ri, ki), vi in large_q_map.items():
            if vi == 1: 
                continue
            for idx in range(li, ri + 1, ki):
                multiplier[idx] = (multiplier[idx] * vi) % MOD
                
        # 2. Process Small k queries using difference arrays
        # Complexity: B * N
        for k in range(1, B):
            if not small_k_queries[k]:
                continue
            
            # diff array tracks changes in the product for step size k
            diff = [1] * (n + k)
            for li, ri, vi in small_k_queries[k]:
                diff[li] = (diff[li] * vi) % MOD
                # Find the last index within [li, ri] in the sequence li, li+k, ...
                last_idx = li + ((ri - li) // k) * k
                # "Stop" the multiplication propagation at last_idx + k
                diff[last_idx + k] = (diff[last_idx + k] * inverses[vi]) % MOD
            
            # Transform difference array into prefix products with step k
            for i in range(k, n):
                diff[i] = (diff[i] * diff[i-k]) % MOD
            
            # Apply the computed products to the main multiplier array
            for i in range(n):
                if diff[i] != 1:
                    multiplier[i] = (multiplier[i] * diff[i]) % MOD
        
        # Final Step: Calculate the bitwise XOR of all final elements
        ans = 0
        for i in range(n):
            # Compute nums[idx] * vi % MOD
            final_val = (nums[i] * multiplier[i]) % MOD
            ans ^= final_val
            
        return ans