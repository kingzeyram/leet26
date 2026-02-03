from typing import List

class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)

        # A trionic array must have at least 3 elements
        if n < 3:
            return False

        i = 0  # pointer used to walk through the array

        # =========================
        # Phase 1: Strictly Increasing
        # nums[0] < nums[1] < ... < nums[p]
        # =========================
        while i + 1 < n and nums[i] < nums[i + 1]:
            i += 1

        # If we never moved, no increasing part exists
        if i == 0:
            return False

        # =========================
        # Phase 2: Strictly Decreasing
        # nums[p] > nums[p+1] > ... > nums[q]
        # =========================
        p = i  # mark the peak index

        while i + 1 < n and nums[i] > nums[i + 1]:
            i += 1

        # If we never moved, no decreasing part exists
        if i == p:
            return False

        # =========================
        # Phase 3: Strictly Increasing Again
        # nums[q] < nums[q+1] < ... < nums[n-1]
        # =========================
        q = i  # mark the valley index

        while i + 1 < n and nums[i] < nums[i + 1]:
            i += 1

        # If we never moved, no final increasing part exists
        if i == q:
            return False

        # =========================
        # Final validation:
        # Must reach the last index for a valid trionic array
        # =========================
        return i == n - 1
