// https://users.monash.edu/~lloyd/tildeAlgDS/Sort/Flag/
// https://leetcode.com/problems/sort-colors/
//https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5212388#learning-tools
// method-1
/*
apply count sort, TC: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &nums, int x, int y)
{
    int t = nums[x];
    nums[x] = nums[y];
    nums[y] = t;
}
void sortColors(vector<int> &nums)
{
    int n = nums.size() - 1, l = 0, m = 0;

    while (m <= n)
    {
        if (nums[m] == 0)
        {
            swap(nums, m++, l++);
        }
        else if (nums[m] == 2)
        {
            swap(nums, m, n--);
        }
        else
        {
            m++;
        }
    }
}