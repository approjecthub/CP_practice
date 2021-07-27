//https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return nums;
        }
        int prefix[n+1];
        int suffix[n+1];
        
        prefix[0] = 1;
        suffix[n] = 1;
        
        for(int i=1; i<=n;i++){
            prefix[i] = nums[i-1]*prefix[i-1];
            
        }
        
        
        for(int i=n-1;i>=0;i--){
            suffix[i] = suffix[i+1]*nums[i];
            
        }
        
        vector<int> ans;
        
        for (int i=1;i<=n;i++){
            
            ans.push_back(prefix[i-1] * suffix[i]);
        }
        
        return ans;
        
    }
};
