// https://leetcode.com/problems/find-peak-element/
// https://www.youtube.com/watch?v=OINnBJTRrMU

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int low = 0, n = nums.size();
    int high = n - 1;

    if (n == 1)
        return 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midl = mid - 1 >= 0 ? nums[mid - 1] : INT_MIN;
        int midr = mid + 1 < n ? nums[mid + 1] : INT_MIN;

        if (midl < nums[mid] && midr < nums[mid])
        {
            return mid;
        }
        else if (nums[mid] < midr)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}