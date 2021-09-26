//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n=nums.size();
        if(n<=1) return 0;
        int i=-1, minm=INT_MAX;
      
        for(int l=n-1;l>=0;l--){
            minm = min(minm,nums[l]);
            if(nums[l]>minm){
                i = l;
            }
        }
        if(i==-1) return 0;
        
        int j=-2, maxm=INT_MIN;
        for(int l=0;l<n;l++){
            maxm = max(maxm,nums[l]);
            if(nums[l]<maxm){
                j = l;
            }
        }
        
        return j-i+1;
    }
};
