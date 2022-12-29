// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;
//the below logics are applicable for distinct element only
//################################ sol1 #############################################
int findPivot(vector<int> &arr)
{
    int pivot = -1, n = arr.size();
    int l = 0, h = n - 1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        int midl = mid - 1 >= 0 ? arr[mid - 1] : INT_MIN;
        int midr = mid + 1 < n ? arr[mid + 1] : INT_MAX;

        if (arr[mid] < midl)
        {
            pivot = mid - 1;
            break;
        }
        else if (arr[mid] > midr)
        {
            pivot = mid;
            break;
        }
        else if (arr[mid] > arr[l])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    return pivot;
}

int bSearch(vector<int> &nums, int l, int h, int target)
{
    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int pivot = findPivot(nums);
    int n = nums.size();
    if (pivot == -1)
    {
        return bSearch(nums, 0, n - 1, target);
    }
    else
    {
        if (nums[pivot] >= target && nums[0] <= target)
        {
            return bSearch(nums, 0, pivot, target);
        }
        else if (nums[pivot + 1] <= target && nums[n - 1] >= target)
        {
            return bSearch(nums, pivot + 1, n - 1, target);
        }
        return -1;
    }
}

//######################################### sol2 ##########################################
int search(vector<int> &nums, int target)
{
    int n = nums.size();

    int l = 0, r = n - 1;
    while (l <= r)
    {

        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
            return mid;

        else if (nums[mid] >= nums[r] && nums[mid] >= nums[l])
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

    return -1;
}