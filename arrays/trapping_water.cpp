//https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
#include <bits/stdc++.h>

using namespace std;

long long trappingWater(int arr[], int n)
{
    int l = 0, r = n - 1, maxl = 0, maxr = 0;
    long long ans = 0;
    while (l < r)
    {
        if (arr[l] <= arr[r])
        {
            if (arr[l] > maxl)
            {
                maxl = arr[l];
            }
            else
            {
                ans += maxl - arr[l];
            }
            l++;
        }
        else
        {
            if (arr[r] > maxr)
            {
                maxr = arr[r];
            }
            else
            {
                ans += maxr - arr[r];
            }
            r--;
        }
    }

    return ans;
}