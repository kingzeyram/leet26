#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to compute the maximum gap formed
    // by removing consecutive bars
    int maxGap(vector<int>& bars) {
        // Sort the bars so consecutive numbers are adjacent
        sort(bars.begin(), bars.end());

        int longest = 1;  // longest streak of consecutive bars
        int current = 1;  // current streak

        for (int i = 1; i < bars.size(); i++) {
            // Check if bars are consecutive
            if (bars[i] == bars[i - 1] + 1) {
                current++;
            } else {
                longest = max(longest, current);
                current = 1;
            }
        }

        longest = max(longest, current);

        // Removing k consecutive bars creates a gap of k + 1
        return longest + 1;
    }

    int maximizeSquareHoleArea(int n, int m,
                               vector<int>& hBars,
                               vector<int>& vBars) {
        int maxHorizontalGap = maxGap(hBars);
        int maxVerticalGap   = maxGap(vBars);

        // Square side is limited by the smaller gap
        int side = min(maxHorizontalGap, maxVerticalGap);

        return side * side;
    }
};

int main() {
    Solution sol;

    // -------- Test Case 1 --------
    int n1 = 2, m1 = 1;
    vector<int> hBars1 = {2, 3};
    vector<int> vBars1 = {2};
    cout << "Output 1: "
         << sol.maximizeSquareHoleArea(n1, m1, hBars1, vBars1)
         << endl;

    // -------- Test Case 2 --------
    int n2 = 1, m2 = 1;
    vector<int> hBars2 = {2};
    vector<int> vBars2 = {2};
    cout << "Output 2: "
         << sol.maximizeSquareHoleArea(n2, m2, hBars2, vBars2)
         << endl;

    // -------- Test Case 3 --------
    int n3 = 2, m3 = 3;
    vector<int> hBars3 = {2, 3};
    vector<int> vBars3 = {2, 4};
    cout << "Output 3: "
         << sol.maximizeSquareHoleArea(n3, m3, hBars3, vBars3)
         << endl;

    return 0;
}
