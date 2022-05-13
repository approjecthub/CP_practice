//https://leetcode.com/problems/longest-consecutive-sequence/
#include <bits/stdc++.h>

using namespace std;
int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    unordered_set<int> uset;

    for (int i = 0; i < n; i++)
    {
        uset.insert(nums[i]);
    }

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int nextNum = nums[i] + 1;
        if (uset.find(nextNum) == uset.end())
        {
            int currSize = 1;
            int prevNum = nums[i] - 1;
            while (uset.find(prevNum) != uset.end())
            {
                currSize++;
                prevNum--;
            }
            ans = max(ans, currSize);
        }
    }

    return ans;
}