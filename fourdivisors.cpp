// Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

 

// Example 1:

// Input: nums = [21,4,7]
// Output: 32
// Explanation: 
// 21 has 4 divisors: 1, 3, 7, 21
// 4 has 3 divisors: 1, 2, 4
// 7 has 2 divisors: 1, 7
// The answer is the sum of divisors of 21 only.
// Example 2:

// Input: nums = [21,21]
// Output: 64
// Example 3:

// Input: nums = [1,2,3,4,5]
// Output: 0

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;  // Stores final answer

        // Loop through each number in the array
        for (int n : nums) {

            int divisorCount = 2;   // 1 and n are always divisors
            int divisorSum = 1 + n; // Start sum with 1 + n

            // Check divisors from 2 to sqrt(n)
            for (int i = 2; i * i <= n; i++) {

                // If i divides n
                if (n % i == 0) {
                    int other = n / i;

                    // If both divisors are the same (perfect square)
                    if (i == other) {
                        divisorCount += 1;
                        divisorSum += i;
                    } 
                    // Otherwise, count both divisors
                    else {
                        divisorCount += 2;
                        divisorSum += i + other;
                    }

                    // More than 4 divisors → stop early
                    if (divisorCount > 4) {
                        break;
                    }
                }
            }

            // If number has exactly 4 divisors, add to answer
            if (divisorCount == 4) {
                totalSum += divisorSum;
            }
        }

        return totalSum;
    }
};
