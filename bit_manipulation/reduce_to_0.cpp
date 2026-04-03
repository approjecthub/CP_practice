// https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * Strategy: In each operation, we can add or subtract a power of 2 from n.
     * To minimize operations, we find the nearest power of 2 to the current number,
     * and replace the number with the absolute difference. Continue until we reach 0.
     * 
     * Example: n = 54
     * - Nearest power: 64, difference = |54-64| = 10
     * - Nearest power: 8, difference = |10-8| = 2
     * - Nearest power: 2, difference = |2-2| = 0
     * Total operations: 3
     */
    int minOperations(int remaining) {
        // Base case: if number is 1, we need 1 operation (subtract 2^0)
        if (remaining == 1)
            return 1;

        int operations = 0;

        // Continue until we reduce the number to 0
        while (remaining > 0) {
            int powerOfTwo = 1;           // Current power of 2 being checked (starts at 2^0)
            int minDifference = INT_MAX;  // Stores minimum difference found so far
            bool foundCloserPower = false;

            // Find the closest power of 2 that is <= remaining
            // Check all powers: 1, 2, 4, 8, 16, 32, ...
            while (powerOfTwo <= remaining) {
                int currentDiff = abs(remaining - powerOfTwo);
                if (minDifference > currentDiff) {
                    foundCloserPower = true;
                    minDifference = currentDiff;
                }
                powerOfTwo <<= 1;  // Multiply by 2 (shift left by 1 bit)
            }

            // Also check the next greater power of 2 (first power > remaining)
            // Sometimes adding to reach the next power is more efficient
            int nextPowerDiff = abs(remaining - powerOfTwo);
            if (minDifference > nextPowerDiff) {
                foundCloserPower = true;
                minDifference = nextPowerDiff;
            }
            
            // Update remaining value to the minimum difference found
            remaining = minDifference;
            
            // Increment operation count if we found a valid power
            if (foundCloserPower)
                operations++;
        }
        
        return operations;
    }
};