// https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5235660#questions

/*
You are playing a game with your 'k'  friends. You have an array of N coins,
 at each index i you have a coin of value a[i]. Your task is to divide the coins,
 among a group of K friends by doing consecutive segments (k-subarrays) of the array.

 Each friend will get a total sum of the coins in that subarray.
  Since all your friends are greedy, and they will pick
  the largest k-1  segments and you will get the smallest segment.
   Find out the maximum value you can make by making an optimal partition.

Note : The coins array may or may not be sorted!
*/

//TC:O(n), we do need sorting here because we are assigning subarrays(segments) to each.
#include <bits/stdc++.h>
using namespace std;

bool isValidDistance(vector<int> arr, int k, int dis)
{
    int count = 0, temp = 0, n = arr.size();
    for (int i = 0; i < n; i++)
    {
        temp += arr[i];
        if (temp >= dis)
        {
            count++;
            temp = 0;
        }
    }

    return count >= k;
}

int getCoins(vector<int> arr, int k)
{

    int l = arr[0], n = arr.size();
    int h = 0, ans = -1;
    for (int i = 0; i < n; i++)
    {
        h += arr[i];
    }

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (isValidDistance(arr, k, mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> coins = {1, 2, 3, 4};
    int k = 4;
    cout << getCoins(coins, k) << endl;
    return 0;
}
