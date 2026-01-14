#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Event {
        long long y;
        int type;          // +1 = add interval, -1 = remove interval
        long long x1, x2;
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;

        /* -----------------------------------
           Step 1: Create sweep-line events
        ----------------------------------- */
        for (auto &s : squares) {
            long long x = s[0];
            long long y = s[1];
            long long l = s[2];

            events.push_back({y, +1, x, x + l});
            events.push_back({y + l, -1, x, x + l});
        }

        sort(events.begin(), events.end(),
             [](const Event &a, const Event &b) {
                 return a.y < b.y;
             });

        multiset<pair<long long, long long>> active;
        vector<tuple<long long, long long, long long>> slabs;

        /* -----------------------------------
           Helper: union width of x-intervals
        ----------------------------------- */
        auto unionWidth = [&]() {
            if (active.empty()) return 0LL;

            vector<pair<long long, long long>> v(
                active.begin(), active.end());
            sort(v.begin(), v.end());

            long long width = 0;
            long long L = v[0].first, R = v[0].second;

            for (int i = 1; i < (int)v.size(); i++) {
                if (v[i].first > R) {
                    width += R - L;
                    L = v[i].first;
                    R = v[i].second;
                } else {
                    R = max(R, v[i].second);
                }
            }
            width += R - L;
            return width;
        };

        /* -----------------------------------
           Step 2: Sweep over Y
        ----------------------------------- */
        long long prevY = events[0].y;
        long long currWidth = 0;

        for (int i = 0; i < (int)events.size(); i++) {
            long long y = events[i].y;

            if (y > prevY && currWidth > 0) {
                slabs.push_back({prevY, y, currWidth});
            }

            while (i < (int)events.size() && events[i].y == y) {
                if (events[i].type == 1)
                    active.insert({events[i].x1, events[i].x2});
                else
                    active.erase(active.find({events[i].x1, events[i].x2}));
                i++;
            }
            i--;

            currWidth = unionWidth();
            prevY = y;
        }

        /* -----------------------------------
           Step 3: Total union area
        ----------------------------------- */
        long double totalArea = 0;
        for (auto &s : slabs) {
            long long y1, y2, w;
            tie(y1, y2, w) = s;
            totalArea += (long double)(y2 - y1) * w;
        }

        long double half = totalArea / 2.0;

        /* -----------------------------------
           Step 4: Binary search answer
        ----------------------------------- */
        auto areaBelow = [&](long double y) {
            long double area = 0;
            for (auto &s : slabs) {
                long long y1, y2, w;
                tie(y1, y2, w) = s;

                if (y <= y1) break;
                area += (long double)(min((long double)y2, y) - y1) * w;
                if (y < y2) break;
            }
            return area;
        };

        long double lo = 0, hi = 1e18;
        for (int i = 0; i < 80; i++) {
            long double mid = (lo + hi) / 2;
            if (areaBelow(mid) < half)
                lo = mid;
            else
                hi = mid;
        }

        return (double)lo;
    }
};

/* -----------------------------------
   Main function (for VS Code testing)
----------------------------------- */
int main() {
    Solution sol;

    vector<vector<int>> squares1 = {{0,0,1},{2,2,1}};
    cout << fixed << setprecision(5)
         << sol.separateSquares(squares1) << endl;

    vector<vector<int>> squares2 = {{0,0,2},{1,1,1}};
    cout << fixed << setprecision(5)
         << sol.separateSquares(squares2) << endl;

    return 0;
}
