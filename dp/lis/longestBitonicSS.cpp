// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

int LongestBitonicSequence(vector<int> nums)
{
    // code here
    int n = nums.size();

    vector<int> dp1(n, 1), dp2(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] > nums[j] && dp1[j] + 1 > dp1[i])
            {
                dp1[i] = dp1[j] + 1;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > nums[j] && dp2[j] + 1 > dp2[i])
            {
                dp2[i] = dp2[j] + 1;
            }
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {

        int temp1 = dp1[i], temp2 = 0;

        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[i] && dp2[j] > temp2)
            {
                temp2 = dp2[j];
            }
        }

        ans = max(ans, temp1 + temp2);
    }

    return ans;
}