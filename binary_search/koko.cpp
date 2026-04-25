// https://leetcode.com/problems/koko-eating-bananas/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int isValidSpeed(vector<int>& piles, int h, int speed) {
            long long time = 0;
            for (int i = 0; i < piles.size(); i++) {
                time += ceil((double)piles[i] / speed);
            }
            // cout<<"time: "<<time<<", speed: "<<speed<<endl;
            return time <= h;
        }
        int minEatingSpeed(vector<int>& piles, int h) {
            int maxmSpeed = *max_element(piles.begin(), piles.end());
            // cout<<"maxmSpeed: "<<maxmSpeed<<endl;
            int l = 1, r = maxmSpeed, ans = maxmSpeed;
    
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (isValidSpeed(piles, h, mid)) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return ans;
        }
    };