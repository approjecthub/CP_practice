//https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/

bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp (n,INT_MAX);
        dp[0]=0;
        for(int i=1; i<n;i++){
            
            int temp =INT_MAX;
            
            for(int j = 0;j<i; j++){
                if(i-j<= nums[j]){
                    temp = min(dp[j], temp);
                    
                }
            }
            
            if(temp!=INT_MAX ){
                dp[i] = 1+temp;
            }
        }
        
        return dp[n-1]!=INT_MAX ;
    }
