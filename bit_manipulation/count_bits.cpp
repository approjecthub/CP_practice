// https://leetcode.com/problems/counting-bits/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        int p = 1;

        for(int i=2; i<=n; i++) {

            if((i & (i-1))==0) {
                p = i;
            }
            dp[i] = 1 + dp[i - p];
        }
        return dp;
    }
};