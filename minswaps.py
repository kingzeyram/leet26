# 1536. Minimum Swaps to Arrange a Binary Grid
# Medium
# Topics
# premium lock icon
# Companies
# Hint
# Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

# A grid is said to be valid if all the cells above the main diagonal are zeros.

# Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

# The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

 

# Example 1:


# Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
# Output: 3
# Example 2:


# Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
# Output: -1
# Explanation: All rows are similar, swaps have no effect on the grid.
# Example 3:


# Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
# Output: 0
 

# Constraints:

# n == grid.length == grid[i].length
# 1 <= n <= 200
# grid[i][j] is either 0 or 1

class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n = len(grid)
        # Precompute trailing zeros for each row
        zeros = []
        for row in grid:
            count = 0
            for i in range(n - 1, -1, -1):
                if row[i] == 0:
                    count += 1
                else:
                    break
            zeros.append(count)
        
        res = 0
        for i in range(n):
            target = n - 1 - i
            # Find the first row from i onwards that meets the target
            found = False
            for j in range(i, n):
                if zeros[j] >= target:
                    # Greedily pick the first valid row and bubble it up
                    res += (j - i)
                    # Shift elements to simulate the swaps
                    row_to_move = zeros.pop(j)
                    zeros.insert(i, row_to_move)
                    found = True
                    break
            
            if not found:
                return -1
                
        return res