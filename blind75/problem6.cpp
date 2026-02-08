// https://leetcode.com/problems/maximum-product-subarray/description/
// Topics: Dynamic Programming, Array

/**
 * Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.
 * elements can be -ve
 * if no. of -ve elements are even, then their product can contribute
 * Now for odd numbers, we need to omit one -ve number, after omitting that either left or right subarray will be the answer
 * Now if we have 0 as current element, then again we need to omit it, after omitting that either left or right subarray will be the answer
 * 
 * video explanation: https://www.youtube.com/watch?v=hnswaLJvr6g
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), countOfNeg = 0, 
        ans=INT_MIN, forward =1, reverse =1;

        for(int i=0; i<n; i++){
            forward *= nums[i];
            reverse *= nums[n-i-1];

            ans = max(forward, max(reverse, ans));
            forward = forward==0?1:forward;
            reverse = reverse==0?1:reverse;
        }

        return ans;
    }
};