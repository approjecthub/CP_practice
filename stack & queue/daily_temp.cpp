//https://leetcode.com/problems/daily-temperatures/

vector<int> dailyTemperatures(vector<int> &arr)
{
    stack<pair<int, int>> s1;
    int n = arr.size() - 1;
    vector<int> ans(n + 1, 0);
    s1.push({arr[n], n});
    for (int i = n; i >= 0; i--)
    {
        // cout<<arr[i]<<" , "<<s1.size()<<endl;
        if (s1.size() > 0 && s1.top().first <= arr[i])
        {
            while (s1.size() > 0 && s1.top().first <= arr[i])
            {
                s1.pop();
            }
            if (s1.size() > 0)
            {
                ans[i] = s1.top().second - i;
            }
            else
            {
                ans[i] = 0;
            }
        }
        else
        {
            ans[i] = 1;
        }
        s1.push({arr[i], i});
    }

    return ans;
}