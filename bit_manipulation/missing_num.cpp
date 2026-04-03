// https://leetcode.com/problems/missing-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // int sum = n * (n + 1) / 2;

        // for (int num : nums) {
        //     sum -= num;
        // }

        // return sum;

        int xorr = 0;
        for(int i=0; i<=n; i++) {
            xorr ^= i;
            if(i < n) {
                xorr ^= nums[i];
            }
        }
        return xorr;
    }
};