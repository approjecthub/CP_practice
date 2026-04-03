// https://leetcode.com/problems/longest-valid-parentheses/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), cnt=0, ans=0, left=0, right=0;

        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                cnt++;
            } else if(s[i] == ')') {
                cnt--;
                if(cnt >= 0) {
                    cnt = 0;
                }
            }

            if(cnt < 0) {
                cnt = 0;
            }
            else if(cnt == 0) {
                ans++;
            }
        }
        return ans;
    }
};