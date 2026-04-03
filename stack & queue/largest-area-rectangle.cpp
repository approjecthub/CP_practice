// https://leetcode.com/problems/largest-rectangle-in-histogram/
// Topics: Stack, Monotonic Stack, Histogram

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextSmaller(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> ans(n, n); // default to n (out of bounds) if no smaller element exists
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        { // traverse from right to left
            while (st.size() > 0 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.size() > 0)
            {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> ans(n, -1); // default to -1 (out of bounds) if no smaller element exists
        stack<int> st;
        for (int i = 0; i < n; i++)
        { // traverse from left to right
            while (st.size() > 0 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.size() > 0)
            {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int ans = 0;
        vector<int> ns = nextSmaller(heights);
        vector<int> ps = prevSmaller(heights);
        for (int i = 0; i < heights.size(); i++)
        {

            int width = ns[i] - ps[i] -1;
            int area = width * heights[i];
            ans = max(ans, area);
        }
        return ans;
    }
};