// https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5166020#overview

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> arr)
{
    int n = arr.size(), maxsum = 0, currsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        if (currsum > maxsum)
        {
            maxsum = currsum;
        }

        if (currsum < 0)
        {
            currsum = 0;
        }
    }

    return maxsum;
}