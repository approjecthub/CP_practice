// https://leetcode.com/problems/reverse-bits/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        for(int i=1; i<32; i++){
            if(n & (1<<i)) {
                ans |= 1<<(31 - i);
            }
        }
        return ans;
    }
};