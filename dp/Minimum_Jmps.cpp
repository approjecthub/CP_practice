// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
// bottom up
void solve(int A[], int N, vector<int> &dp)
{
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        int m = min(A[i], N - i - 1);
        if (i != 0 && dp[i] == -1)
            break;
        for (int j = m; j >= 1; j--)
        {
            if (dp[i + j] == -1 || dp[i + j] > 1 + dp[i])
            {
                dp[i + j] = 1 + dp[i];
            }
            else
            {
                break;
            }
        }
    }
}
int minJumps(int A[], int N)
{
    // Your code here
    vector<int> dp(N, -1);
    solve(A, N, dp);
    return dp[N - 1];
}

// https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/

bool canJump(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {

        int temp = INT_MAX;

        for (int j = 0; j < i; j++)
        {
            if (i - j <= nums[j])
            {
                temp = min(dp[j], temp);
            }
        }

        if (temp != INT_MAX)
        {
            dp[i] = 1 + temp;
        }
    }

    return dp[n - 1] != INT_MAX;
}
