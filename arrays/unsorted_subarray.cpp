#include <bits/stdc++.h>
using namespace std;
// ######################### solution 1 ##############################################
int findUnsortedSubarray(vector<int> &nums)
{
    vector<int> nums_sorted = nums;
    sort(nums_sorted.begin(), nums_sorted.end());
    int n = nums.size();
    if (n <= 1)
        return 0;
    int l = 0, r = n - 1;
    while (l < n)
    {
        if (nums[l] != nums_sorted[l])
            break;
        l++;
    }
    if (l == n)
        return 0;
    while (r >= 0)
    {
        if (nums[r] != nums_sorted[r])
            break;
        r--;
    }
    return r - l + 1;
}
// ######################### solution 2 ##############################################
int findUnsortedSubarray(vector<int> &nums)
{

    int n = nums.size();
    if (n <= 1)
        return 0;
    int i = -1, minm = INT_MAX;

    for (int l = n - 1; l >= 0; l--)
    {
        minm = min(minm, nums[l]);
        if (nums[l] > minm)
        {
            i = l;
        }
    }
    if (i == -1)
        return 0;

    int j = -2, maxm = INT_MIN;
    for (int l = 0; l < n; l++)
    {
        maxm = max(maxm, nums[l]);
        if (nums[l] < maxm)
        {
            j = l;
        }
    }

    return j - i + 1;
}

// ######################### solution 3 ##############################################
int findUnsortedSubarray(vector<int> &arr)
{
    int n = arr.size(), l = 0, r = -1, maxr = INT_MIN, minl = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < maxr)
        {
            r = i;
        }
        else
        {
            maxr = arr[i];
        }

        if (arr[n - i - 1] > minl)
        {
            l = n - i - 1;
        }
        else
        {
            minl = arr[n - i - 1];
        }
    }

    return r - l + 1;
}