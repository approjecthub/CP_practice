//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums_sorted = nums;
        sort(nums_sorted.begin(), nums_sorted.end());
        int n=nums.size();
        if(n<=1) return 0;
        int l=0,r=n-1;
        while(l<n){
            if(nums[l]!=nums_sorted[l]) break;
            l++;
        }
        if(l==n)return 0;
        while(r>=0){
            if(nums[r]!=nums_sorted[r]) break;
            r--;
        }
        return r-l+1;
    }
};
