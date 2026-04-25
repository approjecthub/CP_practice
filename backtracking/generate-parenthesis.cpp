// https://leetcode.com/problems/generate-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<string> &ans, string temp, int open, int close, int n)
    {
        if (temp.size() == 2 * n)
        {
            ans.push_back(temp);
            return;
        }

        if (open == close)
        {
            solve(ans, temp + '(', open - 1, close, n);
        }
        else if (open < close)
        {
            if (open > 0)
                solve(ans, temp + '(', open - 1, close, n);
            solve(ans, temp + ')', open, close - 1, n);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string temp;
        int open = n, close = n;
        solve(ans, temp, open, close, n);
        return ans;
    }
};