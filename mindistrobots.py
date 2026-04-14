class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        # Sort both to ensure no-crossing property holds
        robot.sort()
        factory.sort()
        
        m, n = len(robot), len(factory)
        
        # dp[i][j] = min distance for first i factories to fix first j robots
        # Initialize with a very large value (infinity)
        dp = [[float('inf')] * (m + 1) for _ in range(n + 1)]
        
        # Base case: 0 robots fixed by any number of factories costs 0
        for i in range(n + 1):
            dp[i][0] = 0
            
        for i in range(1, n + 1):
            f_pos, f_limit = factory[i-1]
            for j in range(1, m + 1):
                # Option 1: Current factory i fixes ZERO robots
                dp[i][j] = dp[i-1][j]
                
                # Option 2: Current factory i fixes 'k' robots (1 to f_limit)
                # We must ensure we have enough robots left to pick k
                total_dist = 0
                for k in range(1, min(j, f_limit) + 1):
                    # Robot index is j - k (we take the k most recent robots)
                    total_dist += abs(robot[j - k] - f_pos)
                    
                    if dp[i-1][j-k] != float('inf'):
                        dp[i][j] = min(dp[i][j], dp[i-1][j-k] + total_dist)
                        
        return dp[n][m]