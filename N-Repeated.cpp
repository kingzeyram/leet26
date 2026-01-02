// 961. N-Repeated Element in Size 2N Array
// Easy
// Topics
// premium lock icon
// Companies
// You are given an integer array nums with the following properties:

// nums.length == 2 * n.
// nums contains n + 1 unique elements.
// Exactly one element of nums is repeated n times.
// Return the element that is repeated n times.

 

// Example 1:

// Input: nums = [1,2,3,3]
// Output: 3
// Example 2:

// Input: nums = [2,1,2,5,3,2]
// Output: 2
// Example 3:

// Input: nums = [5,1,5,2,5,3,5,4]
// Output: 5
 

// Constraints:

// 2 <= n <= 5000
// nums.length == 2 * n
// 0 <= nums[i] <= 104
// nums contains n + 1 unique elements and one of them is repeated exactly n times.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            // If number already exists, it's the repeated one
            if (seen.count(num)) {
                return num;
            }
            seen.insert(num);
        }

        return -1; // Safety return (won't be reached)
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<int> nums1 = {1, 2, 3, 3};
    vector<int> nums2 = {2, 1, 2, 5, 3, 2};
    vector<int> nums3 = {5, 1, 5, 2, 5, 3, 5, 4};

    cout << "Output 1: " << solution.repeatedNTimes(nums1) << endl;
    cout << "Output 2: " << solution.repeatedNTimes(nums2) << endl;
    cout << "Output 3: " << solution.repeatedNTimes(nums3) << endl;

    return 0;
}
