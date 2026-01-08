#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // A very small number to represent -infinity
        // Used because subsequences must be NON-EMPTY
        const int NEG_INF = -1e9;

        // dp[i][j] = maximum dot product using
        // nums1[0..i-1] and nums2[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, NEG_INF));

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // Product of current elements
                int product = nums1[i - 1] * nums2[j - 1];

                // Option 1: Pair nums1[i-1] with nums2[j-1]
                // Either start a new subsequence OR extend a previous one
                int takeBoth = max(
                    product,
                    dp[i - 1][j - 1] + product
                );

                // Option 2: Skip nums1[i-1]
                int skipNums1 = dp[i - 1][j];

                // Option 3: Skip nums2[j-1]
                int skipNums2 = dp[i][j - 1];

                // Take the best of all choices
                dp[i][j] = max({takeBoth, skipNums1, skipNums2});
            }
        }

        // Answer is the best dot product using full arrays
        return dp[n][m];
    }
};
