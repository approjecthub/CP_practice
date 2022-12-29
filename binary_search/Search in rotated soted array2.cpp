// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <bits/stdc++.h>
using namespace std;
bool search(vector<int> &nums, int target)
{
    int n = nums.size();

    int l = 0, r = n - 1;
    while (l <= r)
    {

        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
            return true;

        if (nums[mid] == nums[r] && nums[mid] == nums[l])
        {
            l++;
        }
        else if (nums[mid] > nums[r])
        { // mid is on line 1
            if (target >= nums[l] && target < nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        else
        {
            if (target <= nums[r] && target > nums[mid])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }

    return false;
}