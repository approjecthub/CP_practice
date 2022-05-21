// https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
using namespace std;

//############ naive approach ###############
//##### sort the array based on start time then start merging ###############
//###### without sorting we can not gurantee proper merge ##########
static bool customComp(vector<int> a, vector<int> b)
{
    return a[0] <= b[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<bool> isVisited(n, false);
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end(), customComp);

    for (int i = 0; i < n; i++)
    {
        if (!isVisited[i])
        {
            int strt = intervals[i][0];
            int end = intervals[i][1];

            for (int j = 0; j < n; j++)
            {
                if (i == j || isVisited[j])
                {
                    continue;
                }
                if (intervals[j][0] >= strt && intervals[j][0] <= end)
                {
                    isVisited[j] = true;
                    strt = min(strt, intervals[j][0]);
                    end = max(end, intervals[j][1]);
                }
            }
            isVisited[i] = true;
            ans.push_back({strt, end});
        }
    }

    return ans;
}

// #################### sol2 ############################
// TC: O(nlogn), SC: O(1)

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size(), i = 0;
    if (n == 0)
    {
        return {};
    }
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    while (i < n)
    {
        int strt = intervals[i][0], end = intervals[i][1], j = i;

        while (j < n && intervals[j][0] <= end && intervals[j][0] >= strt)
        {
            strt = min(strt, intervals[j][0]);
            end = max(end, intervals[j][1]);
            j++;
        }
        ans.push_back({strt, end});
        if (i == j)
        {
            i++;
        }
        else
        {
            i = j;
        }
    }

    return ans;
}