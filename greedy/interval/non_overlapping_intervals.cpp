// https://leetcode.com/problems/non-overlapping-intervals/

#include <bits/stdc++.h>
using namespace std;
// ########################### sol1 #################################

class Solution
{
public:
    bool static compare(vector<int> a, vector<int> b)
    {
        if (a[1] < b[1])
        {
            return true;
        }
        else if (a[1] == b[1])
        {
            return a[0] > b[0];
        }
        else
        {
            return false;
        }
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), compare);
        int start = intervals[0][0];
        int end = intervals[0][1];
        int ans = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (end > intervals[i][0])
            {
                ans++;
            }
            else
            {
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        return ans;
    }
};

// ################################# sol2 ################################

static bool compSort(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
    {
        return true;
    }
    else if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    else
    {
        return false;
    }
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), compSort);
    int ans = 0, n = intervals.size(), i = 0;
    while (i < n)
    {
        int strt = intervals[i][0];
        int end = intervals[i][1];
        int j = i + 1;
        while (j < n && intervals[j][0] >= strt && intervals[j][0] < end)
        {
            ans++;
            end = min(end, intervals[j][1]);
            j++;
        }
        i = j;
    }

    return ans;
}

//################################ sol 3 ###########################################

static bool compSort(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
    {
        return true;
    }
    else if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    else
    {
        return false;
    }
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), compSort);
    int ans = 0, n = intervals.size(), i = 1;
    int strt = intervals[0][0];
    int end = intervals[0][1];
    while (i < n)
    {
        if (end > intervals[i][0])
        {
            end = min(end, intervals[i][1]);
            ans++;
        }
        else
        {
            strt = intervals[i][0];
            end = intervals[i][1];
        }
        i++;
    }

    return ans;
}

// ################################### sol4 ######################################
static bool compSort(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), compSort);
    int ans = 0, n = intervals.size(), i = 1;
    if (intervals.size() == 0)
        return 0;
    int end = intervals[0][1];
    while (i < n)
    {
        if (end > intervals[i][0])
        {
            ans++;
        }
        else
        {
            end = intervals[i][1];
        }
        i++;
    }
    return ans;
}