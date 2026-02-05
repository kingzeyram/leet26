from typing import List

class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        # Length of the circular array
        n = len(nums)

        # Result array initialized with zeros
        result = [0] * n

        # Traverse each index in nums
        for i in range(n):
            # Case 1: value is zero → copy zero directly
            if nums[i] == 0:
                result[i] = 0
            else:
                # Case 2 & 3:
                # Positive value → move right
                # Negative value → move left
                # Modulo (%) handles circular wrapping automatically
                new_index = (i + nums[i]) % n

                # Set the value from the landing index
                result[i] = nums[new_index]

        # Return the transformed array
        return result
