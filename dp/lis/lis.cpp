// https://leetcode.com/problems/longest-increasing-subsequence/description/
// Topics: Dynamic Programming, LIS, Binary Search

#include <bits/stdc++.h>
using namespace std;

// nlogn approach
void process(vector<int> &temp, int ele)
{
    int n = temp.size();

    if (n == 0)
        temp.push_back(ele);
    else
    {
        int l = 0, r = n - 1, idx = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (temp[mid] >= ele)
            {
                r = mid - 1;
                idx = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        if (idx != -1)
        {
            temp[idx] = ele;
        }
        else
        {
            temp.push_back(ele);
        }
    }
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        process(temp, nums[i]);
    }
    return temp.size();
}

// easier recursive code, which is intuitive in making the bottom up logic

int solve(vector<int> &nums, int preIdx, int idx)
{
    int n = nums.size();
    if (idx >= n)
        return 0;

    if (preIdx == -1 || nums[idx] > nums[preIdx])
    {
        return max(1 + solve(nums, idx, idx + 1),
                   solve(nums, preIdx, idx + 1));
    }
    else
    {
        return solve(nums, preIdx, idx + 1);
    }
}
/*
F(preIdx, idx)
    depends on:
        F(preIdx, idx+1)
        F(idx, idx+1)

idx → always increases
preIdx → can stay same OR become idx

In bottom-up DP, The dimension that strictly increases in recursion, Must be filled in reverse order
so idx: n → 0, that makes idx the outer reversed loop.

*/
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    /*
        dp[curr][prev + 1] represents:

        LIS length starting from index = curr
        where the previously chosen element index = prev

        We use (prev + 1) because prev can be -1.
        Mapping:
            prev = -1  → column 0
            prev = 0   → column 1
            prev = 1   → column 2
            ...
    */
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    /*
        Base Case:
        When curr == n (i.e., beyond last index),
        LIS length = 0.
        That is already initialized to 0.
    */

    // Fill rows from bottom to top
    // Because dp[curr][...] depends on dp[curr + 1][...]
    for (int curr = n - 1; curr >= 0; curr--)
    {
        // prev can range from -1 up to curr - 1
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            // Option 1: Skip current element
            int notTake = dp[curr + 1][prev + 1];

            int take = 0;

            // Option 2: Take current element
            if (prev == -1 || nums[curr] > nums[prev])
            {
                /*
                    If we take nums[curr],
                    then curr becomes the new "previous index".

                    So next state becomes:
                        solve(curr, curr + 1)

                    Which maps to:
                        dp[curr + 1][curr + 1]

                    Explanation:
                        row  = curr + 1
                        col  = (newPrev + 1) = (curr + 1)
                */
                take = 1 + dp[curr + 1][curr + 1];
            }

            dp[curr][prev + 1] = max(take, notTake);
        }
    }

    // Starting state: curr = 0, prev = -1
    return dp[0][0];
}


// ############################################################################################################

// int solve(vector<int>& nums, int ele, int idx){
//     int n = nums.size();
//     if(idx>=n) return 0;

//     if(nums[idx]> ele){
//         return max(1+solve(nums, nums[idx], idx+1),
//         solve(nums, ele, idx+1));
//     }
//     else{
//         return solve(nums, ele, idx+1);
//     }
// }
int solve(vector<int> &nums, int ele, int idx,
          int res, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (idx >= n)
        return 0;
    if (dp[idx][ele + res] != -1)
        return dp[idx][ele + res];
    if (nums[idx] > ele)
    {
        dp[idx][ele + res] = max(1 +
                                     solve(nums, nums[idx], idx + 1, res, dp),
                                 solve(nums, ele, idx + 1, res, dp));
    }
    else
    {
        dp[idx][ele + res] = solve(nums, ele, idx + 1, res, dp);
    }
    return dp[idx][ele + res];
}
int lengthOfLIS(vector<int> &nums)
{
    // return solve(nums, INT_MIN, 0);
    int n = nums.size();
    int maxm = INT_MIN, minm = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        maxm = max(maxm, nums[i]);
        minm = min(minm, nums[i]);
    }
    int colsize = maxm + abs(minm) + 2;
    vector<vector<int>> dp(n,
                           vector<int>(colsize, -1));
    return solve(nums, minm - 1, 0, abs(minm) + 1, dp);
}