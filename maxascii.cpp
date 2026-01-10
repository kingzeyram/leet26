#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        // dp[i][j] = minimum ASCII delete sum
        // to make s1[i:] and s2[j:] equal
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case:
        // If s1 is exhausted, delete all remaining chars in s2
        for (int j = m - 1; j >= 0; j--) {
            dp[n][j] = dp[n][j + 1] + (int)s2[j];
        }

        // Base case:
        // If s2 is exhausted, delete all remaining chars in s1
        for (int i = n - 1; i >= 0; i--) {
            dp[i][m] = dp[i + 1][m] + (int)s1[i];
        }

        // Fill the DP table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                // If characters match, no deletion needed
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } 
                // Otherwise, delete from s1 or s2
                else {
                    dp[i][j] = min(
                        (int)s1[i] + dp[i + 1][j],  // delete s1[i]
                        (int)s2[j] + dp[i][j + 1]   // delete s2[j]
                    );
                }
            }
        }

        // Minimum ASCII delete sum to make both strings equal
        return dp[0][0];
    }
};
