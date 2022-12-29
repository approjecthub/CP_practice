// https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5212390#learning-tools

/*
ICPC Standings

Usually, results of competitions are based on the scores of participants. However, we are planning a change for the next year of ICPC. During the registration each team will be able to enter a single positive integer : their preferred place in the ranklist. We would take all these preferences into account, and at the end of the competition we will simply announce a ranklist that would please all of you.

But wait... How would that ranklist look like if it won't be possible to satisfy all the requests?

Suppose that we already have a ranklist. For each team, compute the distance between their preferred place and their place in the ranklist. The sum of these distances will be called the badness  of this ranklist.

Goal
Given team names and their preferred placements find one ranklist with the minimal possible badness.

*/
#include <bits/stdc++.h>
using namespace std;

bool customSort(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}
int badness(vector<pair<string, int>> teams)
{
    // Complete this function to return the min badness
    sort(teams.begin(), teams.end(), customSort);
    int n = teams.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(teams[i].second - (i + 1));
    }
    return ans;
}