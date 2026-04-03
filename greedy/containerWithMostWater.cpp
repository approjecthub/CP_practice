// https://leetcode.com/problems/container-with-most-water/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxArea(vector<int>& height) {
        int maxArea = 0, n = height.size();
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         int area = min(height[i], height[j]) * (j - i);
        //         maxArea = max(maxArea, area);
        //     }
        // }
        // return maxArea;

        int l = 0, r = n - 1;
        while(l < r){
            int area = min(height[l], height[r]) * (r - l);
            maxArea = max(maxArea, area);
            if(height[l] < height[r]) l++;
            else r--;   
        }
        return maxArea;
    }
};