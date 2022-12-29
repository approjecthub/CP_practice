// https://leetcode.com/problems/search-a-2d-matrix/
//  https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5212386#learning-tools

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = -1, col = -1, i, j, mid, m = matrix[0].size(), n = matrix.size();

        // base case
        if (m == 0 or n == 0)
            return false;

        i = 0;
        j = n;
        int i1 = 0, j1 = m, mid1;
        while (i < j)
        {
            mid = (i + j) / 2;
            if (matrix[mid][0] > target && matrix[mid][m - 1] > target)
            {
                j = mid;
            }
            else if (matrix[mid][0] < target && matrix[mid][m - 1] < target)
            {
                i = mid + 1;
            }
            else
            {

                while (i1 < j1)
                {
                    mid1 = (i1 + j1) / 2;

                    if (matrix[mid][mid1] > target)
                    {
                        j1 = mid1;
                    }
                    else if (matrix[mid][mid1] < target)
                    {
                        i1 = mid1 + 1;
                    }
                    else
                    {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};

//######################### sol2 ############################################
pair<int, int> search(int m, int n, vector<vector<int>> v, int k)
{
    // write your code here.
    int lr = 0, hr = m - 1;
    while (lr <= hr)
    {
        int midr = lr + (hr - lr) / 2;

        if (v[midr][0] <= k && v[midr][n - 1] >= k)
        {
            int lc = 0, hc = n - 1;
            while (lc <= hc)
            {
                int midc = lc + (hc - lc) / 2;

                if (v[midr][midc] == k)
                {
                    return {midr, midc};
                }
                else if (v[midr][midc] < k)
                {
                    lc = midc + 1;
                }
                else
                {
                    hc = midc - 1;
                }
            }
        }
        else if (v[midr][n - 1] < k)
        {
            lr = midr + 1;
        }
        else
        {
            hr = midr - 1;
        }
    }

    return {-1, -1};
}

// ################################# sol3 ########################################
bool searchMatrix(vector<vector<int>> &v, int k)
{
    int m = v.size(), n = v[0].size();
    int low = 0, high = (m * n) - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int rowNum = (mid / n), colNum = mid % n;
        if (v[rowNum][colNum] == k)
        {
            return true;
        }
        else if (v[rowNum][colNum] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}
