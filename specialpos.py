# Given an m x n binary matrix mat, return the number of special positions in mat.

# A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

 

# Example 1:


# Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
# Output: 1
# Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
# Example 2:


# Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
# Output: 3
# Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
 

# Constraints:

# m == mat.length
# n == mat[i].length
# 1 <= m, n <= 100
# mat[i][j] is either 0 or 1.

class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        
        # Step 1: Count ones in each row and each column
        row_sums = [0] * m
        col_sums = [0] * n
        
        for r in range(m):
            for c in range(n):
                if mat[r][c] == 1:
                    row_sums[r] += 1
                    col_sums[c] += 1
        
        # Step 2: Identify special positions
        special_count = 0
        for r in range(m):
            for c in range(n):
                # A position is special if it's a 1 AND 
                # it's the only 1 in its row and column
                if mat[r][c] == 1:
                    if row_sums[r] == 1 and col_sums[c] == 1:
                        special_count += 1
                        
        return special_count