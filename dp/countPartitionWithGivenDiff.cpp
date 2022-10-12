// https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
int mod = (int)1e9 + 7;

int subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<int>prev(k+1,0);
    vector<int>curr(k+1);
    
    if(arr[0]==0) prev[0] = 2;
    else prev[0] = 1;
    if(arr[0]!=0 && arr[0]<=k) prev[arr[0]] = 1;
    
    for(int i=1; i<n; i++){
        for(int j=0; j<=k; j++){
            int notTake = prev[j];
            int take=0;
            if(j>=arr[i]){
                take=prev[j-arr[i]];
            }
            curr[j] = (notTake + take)%mod;
        }
        prev = curr;
    }

    return prev[k];
}

int subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (arr[0] != 0 && arr[0] <= k)
        dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int notTake = dp[i - 1][j];
            int take = 0;
            if (j >= arr[i])
            {
                take = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = (notTake + take) % mod;
        }
    }

    return dp[n - 1][k];
}

// int solve(vector<int> &arr, int ss, int n, int total, int d){
//     if(n==0){
//         if(ss==((total-d)/2)) return 1;
//         else return 0;
//     }
//     else{
//         return solve(arr,ss+arr[n-1], n-1, total, d)
//             + solve(arr,ss, n-1, total, d);
//     }
// }

int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    if ((total - d) > 0 && (total - d) % 2 == 0)
    {
        //         return solve(arr, 0,n,total,d);
        return subsetSumToK(n, (total - d) / 2, arr);
    }
    else
        return 0;
}