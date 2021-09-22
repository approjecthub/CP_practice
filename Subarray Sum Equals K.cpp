//https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0,j=0, temp=0;
        for(int i=0; i<nums.size(); i++){
            temp+= nums[i];
            if (temp==k){
                ans++;
            }
            else if(temp>k){
                while(temp>k && j<i){
                    temp -= nums[j];
                    j++;
                    
                }
                if (temp==k){
                ans++;
            }
            }
        }
        return ans;
    }
};
