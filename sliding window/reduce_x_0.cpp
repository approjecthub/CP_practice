// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int naiveSoln(vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        vector<int> suffixSum(n + 1, 0);

        // prefixSum[i] = sum of first i elements
        for (int i = 1; i <= n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        // suffixSum[i] = sum from index i to end
        for (int i = n - 1; i >= 0; i--)
        {
            suffixSum[i] = suffixSum[i + 1] + nums[i];
        }

        int minOperations = INT_MAX;
        // i = number of elements taken from left
        // j = starting index of elements taken from right
        // Constraint: i <= j (no overlap)
        for (int i = 0; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                if (prefixSum[i] + suffixSum[j] == x)
                {
                    minOperations = min(minOperations, i + (n - j));
                }
            }
        }
        return minOperations == INT_MAX ? -1 : minOperations;
    }

    int betterSoln(vector<int> &nums, int x)
    {
        int n = nums.size();
        int totalSum = 0;

        for (int num : nums)
        {
            totalSum += num;
        }

        int target = totalSum - x, l = 0, r = 0, maxLength = -1;
        while (r < n)
        {
            target -= nums[r];
            while (target < 0 && l < n)
            {
                target += nums[l];
                l++;
            }
            if (target == 0 && maxLength < r - l + 1)
            {
                maxLength = r - l + 1;
            }
            r++;
        }
        return maxLength == -1 ? -1 : n - maxLength;
    }

    int minOperations(vector<int> &nums, int x)
    {
        return betterSoln(nums, x);
    }
};