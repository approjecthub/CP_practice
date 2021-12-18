//https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1#

int solveTopDown(vector<int> & dp, int arr[], int n){
        if(n<= 0) return 0;
        if(dp[n]!=-1) return dp[n];
        
        dp[n] = max(arr[n-1] + solve(dp, arr, n-2),
                solve(dp, arr, n-1));
                
        return dp[n];
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // recursive code
        // if(n<= 0) return 0;
        
        // return max(arr[n-1] + FindMaxSum(arr, n-2),
        //         FindMaxSum(arr, n-1));
        
        //top-down approach
        // vector<int> dp(n+1, -1);
        // return solveTopDown(dp, arr, n);
        
      
        //bottom-up approach
        vector<int> dp(n,0);
        
        // dp[0] = arr[0];
        // dp[1] = max(arr[0], arr[1]);
        for(int i=0; i<n;i++){
            int temp1 = arr[i] + ((i-2>=0) ? dp[i-2] :0);
            int temp2 = (i-1>=0)? dp[i-1] :0;
            // dp[i] = max(arr[i] + dp[i-2], dp[i-1]);
            dp[i] = max(temp1, temp2);
        }
        
        return dp[n-1];
    }
