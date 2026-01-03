// 1411. Number of Ways to Paint N × 3 Grid
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

// Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.

 

// Example 1:


// Input: n = 1
// Output: 12
// Explanation: There are 12 possible way to paint the grid as shown.
// Example 2:

// Input: n = 5000
// Output: 30228214
 

// Constraints:

// n == grid.length
// 1 <= n <= 5000

#include <bits/stdc++.h>
using namespace std;

/*
  LeetCode 1411: Number of Ways to Paint N × 3 Grid

  We track two pattern types per row:
  1. same (ABA): first and third cells have the same color
  2. diff (ABC): all three cells have different colors

  Transitions:
    same = same * 3 + diff * 2
    diff = same * 2 + diff * 2
*/

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        // Base case for row 1
        long long same = 6;  // ABA patterns
        long long diff = 6;  // ABC patterns

        // Build row by row
        for (int i = 2; i <= n; i++) {
            long long newSame = (same * 3 + diff * 2) % MOD;
            long long newDiff = (same * 2 + diff * 2) % MOD;

            same = newSame;
            diff = newDiff;
        }

        return (same + diff) % MOD;
    }
};

// -------------------
// Local Testing (VS Code)
// -------------------
int main() {
    Solution sol;

    int n;
    cout << "Enter number of rows (n): ";
    cin >> n;

    cout << "Number of ways: " << sol.numOfWays(n) << endl;

    return 0;
}
