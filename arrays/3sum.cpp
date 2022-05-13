#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &arr)
{
    int target = 0, n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int l = i + 1, h = n - 1;
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        while (l < h)
        {
            if (arr[i] + arr[l] + arr[h] < target)
            {
                l++;
            }
            else if (arr[i] + arr[l] + arr[h] > target)
            {
                h--;
            }
            else
            {
                if (!ans.empty())
                {
                    vector<int> last = ans.back();
                    if (last[0] == arr[i] && last[1] == arr[l] && last[2] == arr[h])
                    {
                        l++;
                        h--;
                        continue;
                    }
                }
                ans.push_back({arr[i], arr[l], arr[h]});
                l++;
                h--;
            }
        }
    }

    return ans;
}