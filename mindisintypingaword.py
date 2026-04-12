class Solution:
    def minimumDistance(self, word: str) -> int:
        def get_dist(p1, p2):
            # If either finger is not yet placed, the cost to move to a letter is 0
            if p1 == 26 or p2 == 26:
                return 0
            # Manhattan distance on a 6-column grid
            return abs(p1 // 6 - p2 // 6) + abs(p1 % 6 - p2 % 6)
        
        # dp[p] represents the minimum distance to reach the current state
        # where one finger is at word[i-1] and the 'other' finger is at position p.
        # 26 represents the "null" state (finger not yet placed).
        dp = {26: 0}
        
        # Convert word to numerical positions 0-25
        chars = [ord(c) - ord('A') for c in word]
        
        for i in range(1, len(chars)):
            curr, prev = chars[i], chars[i-1]
            new_dp = {}
            
            for p, cost in dp.items():
                # Option 1: Move the finger that just typed 'prev' to 'curr'
                # The 'other' finger remains at position 'p'
                d1 = cost + get_dist(prev, curr)
                if p not in new_dp or d1 < new_dp[p]:
                    new_dp[p] = d1
                
                # Option 2: Move the 'other' finger from 'p' to 'curr'
                # The finger that was at 'prev' becomes the 'other' finger
                d2 = cost + get_dist(p, curr)
                if prev not in new_dp or d2 < new_dp[prev]:
                    new_dp[prev] = d2
                    
            dp = new_dp
            
        return min(dp.values())