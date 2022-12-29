// https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1/#
/*
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.
TC: O(logn)
*/

#include <bits/stdc++.h>
using namespace std;

int lowerBound(int arr[], int n, int x)
{
    int l = 0, h = n - 1, pos = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == x)
        {
            pos = mid;
            h = mid - 1;
        }
        else if (arr[mid] > x)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return pos;
}

int upperBound(int arr[], int n, int x)
{
    int l = 0, h = n - 1, pos = -2;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == x)
        {
            pos = mid;
            l = mid + 1;
        }
        else if (arr[mid] > x)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return pos;
}
int count(int arr[], int n, int x)
{
    // code here
    int posl = lowerBound(arr, n, x);
    int posr = upperBound(arr, n, x);
    return posr - posl + 1;
}