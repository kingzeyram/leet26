#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double low = 1e18, high = 0.0;

        // Calculate total area and y-range
        for (auto &s : squares) {
            double y = s[1];
            double l = s[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double target = totalArea / 2.0;

        // Function to compute area below horizontal line y = h
        auto areaBelow = [&](double h) {
            double area = 0.0;
            for (auto &s : squares) {
                double y = s[1];
                double l = s[2];

                if (h <= y) {
                    // No contribution
                    continue;
                } else if (h >= y + l) {
                    // Full square below
                    area += l * l;
                } else {
                    // Partial contribution
                    area += l * (h - y);
                }
            }
            return area;
        };

        // Binary search for minimum y where areaBelow(y) >= target
        for (int i = 0; i < 60; i++) {
            double mid = (low + high) / 2.0;
            if (areaBelow(mid) < target)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
