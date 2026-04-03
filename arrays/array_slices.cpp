// https://leetcode.com/problems/arithmetic-slices/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int naivSoln(vector<int> &nums)
    {
        // O(n^2) time, O(1) space
        int n = nums.size();
        if (n < 3)
            return 0; // Need at least 3 elements
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int tempCnt = 0, tempDiff = 0;
            for (int j = i + 1; j < n; j++)
            {

                if (tempCnt == 0)
                {
                    tempDiff = nums[j] - nums[j - 1];
                    tempCnt++;
                }
                else if (nums[j] - nums[j - 1] == tempDiff)
                {
                    tempCnt++;
                    if (tempCnt >= 2)
                    {
                        ans++;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        return ans;
    }

    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0; // Need at least 3 elements
        int ans = 0, l = 0, r = 0;
        while (r < n)
        {
            /* code */
            if (r - l + 1 < 3)
            {
                r++;
            }
            else if (nums[r] - nums[r - 1] == nums[r - 1] - nums[r - 2])
            {
                ans += (r - l - 1);
                r++;
            }
            else
            {
                l = r - 1;
            }
        }
        return ans;
    }
};