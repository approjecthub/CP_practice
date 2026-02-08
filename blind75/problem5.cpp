// https://leetcode.com/problems/maximum-subarray/description/
// Topics: Kadane's Algorithm, Dynamic Programming, Array

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int j=0, temp=0, n=nums.size(), maxSum=INT_MIN;
        while(j<n){
            temp += nums[j];
            maxSum = max(maxSum, temp);
            if(temp<0){
                temp = 0;
            }
            j++;
        }

        return maxSum;
    }
};