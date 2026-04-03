// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void solve(vector<string> &ans, string digits, string current, int index)
    {
        int n = digits.size();

        if (current.size() == n)
        {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < n; i++)
        {
            char digit = digits[i];
            for (char c : mp[digit])
            {
                // cout<<"digit: "<<digit<<" char: "<<c<<" current: "<<current<<endl;
                solve(ans, digits, current + c, i + 1);
            }
        }
    }

    vector<string> letterCombinations(string digits)
    {

        vector<string> ans;
        if (digits.empty())
            return ans;
        solve(ans, digits, "", 0);
        return ans;
    }
};