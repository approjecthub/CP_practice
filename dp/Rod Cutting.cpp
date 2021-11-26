//https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

int cutRod(int price[], int n) {
        //code here
        // if(n==0){
        //     return 0;
        // }
        
        // int val = 0;
        
        // for(int i=0; i<n;i++){
        //     int x= cutRod(price, n-i-1);
        //     if(x>=0)
        //     val = max(price[i] + cutRod(price, n-i-1), val);
        // }
        
        // return val;
        
        int dp[n];
        dp[0] = price[0];
        for(int i=1;i<n;i++){
            int v=price[i];
            for(int j=0;j<i;j++){
                int divi = (i+1)/(j+1);
                int rem = (i+1)%(j+1);
                int v1 = dp[j]*divi;
                if(rem>0){
                    v1 += dp[rem-1];
                }
                
                v = max(v, v1);
            }
            dp[i]= v;
        }
        return dp[n-1];
    }
