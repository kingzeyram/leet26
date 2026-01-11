#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // Handle empty matrix
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Histogram heights for each column
        vector<int> heights(cols, 0);
        int maxArea = 0;

        // Build histogram row by row
        for (int i = 0; i < rows; i++) {

            // Update histogram heights
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;   // extend vertical bar
                else
                    heights[j] = 0;    // reset bar
            }

            // Calculate largest rectangle for this histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // stores indices
        int maxArea = 0;
        int n = heights.size();

        // Traverse all bars + one extra sentinel bar
        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];

            // Maintain increasing stack
            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                // Width depends on stack state
                int width = st.empty() ? i : i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};
