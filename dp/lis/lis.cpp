// https://leetcode.com/problems/longest-increasing-subsequence/description/

// nlogn approach
void process(vector<int> &temp, int ele)
{
    int n = temp.size();

    if (n == 0)
        temp.push_back(ele);
    else
    {
        int l = 0, r = n - 1, idx = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (temp[mid] >= ele)
            {
                r = mid - 1;
                idx = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        if (idx != -1)
        {
            temp[idx] = ele;
        }
        else
        {
            temp.push_back(ele);
        }
    }
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        process(temp, nums[i]);
    }
    return temp.size();
}

// easier recursive code, which is intuitive in making the bottom up logic

int solve(vector<int> &nums, int preIdx, int idx)
{
    int n = nums.size();
    if (idx >= n)
        return 0;

    if (preIdx == -1 || nums[idx] > nums[preIdx])
    {
        return max(1 + solve(nums, idx, idx + 1),
                   solve(nums, preIdx, idx + 1));
    }
    else
    {
        return solve(nums, preIdx, idx + 1);
    }
}
int lengthOfLIS(vector<int> &nums)
{

    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

    for (int i = n - 1; i >= 0; i--)
    { // currIdx
        for (int j = i - 1; j >= -1; j--)
        { // prevIdx
            if (j == -1 || nums[i] > nums[j])
            {
                dp[i][j + 1] = max(1 + dp[i + 1][i + 1], dp[i + 1][j + 1]);
            }
            else
            {
                dp[i][j + 1] = dp[i + 1][j + 1];
            }
        }
    }

    return dp[0][0];
}

// ############################################################################################################

// int solve(vector<int>& nums, int ele, int idx){
//     int n = nums.size();
//     if(idx>=n) return 0;

//     if(nums[idx]> ele){
//         return max(1+solve(nums, nums[idx], idx+1),
//         solve(nums, ele, idx+1));
//     }
//     else{
//         return solve(nums, ele, idx+1);
//     }
// }
int solve(vector<int> &nums, int ele, int idx,
          int res, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (idx >= n)
        return 0;
    if (dp[idx][ele + res] != -1)
        return dp[idx][ele + res];
    if (nums[idx] > ele)
    {
        dp[idx][ele + res] = max(1 +
                                     solve(nums, nums[idx], idx + 1, res, dp),
                                 solve(nums, ele, idx + 1, res, dp));
    }
    else
    {
        dp[idx][ele + res] = solve(nums, ele, idx + 1, res, dp);
    }
    return dp[idx][ele + res];
}
int lengthOfLIS(vector<int> &nums)
{
    // return solve(nums, INT_MIN, 0);
    int n = nums.size();
    int maxm = INT_MIN, minm = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        maxm = max(maxm, nums[i]);
        minm = min(minm, nums[i]);
    }
    int colsize = maxm + abs(minm) + 2;
    vector<vector<int>> dp(n,
                           vector<int>(colsize, -1));
    return solve(nums, minm - 1, 0, abs(minm) + 1, dp);
}