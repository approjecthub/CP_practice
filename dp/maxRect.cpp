// https://leetcode.com/problems/maximal-rectangle/description/

static int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> prevSmaller(n, 0), nextSmaller(n, 0);
    stack<int> prev, next;

    prev.push(0);
    prevSmaller[0] = -1;
    for (int i = 1; i < n; i++)
    {
        while (prev.size() > 0 &&
               heights[prev.top()] >= heights[i])
        {
            prev.pop();
        }

        if (prev.size() > 0)
        {
            prevSmaller[i] = prev.top();
        }
        else
        {
            prevSmaller[i] = -1;
        }

        if (prev.size() == 0 ||
            heights[prev.top()] < heights[i])
            prev.push(i);
    }

    next.push(n - 1);
    nextSmaller[n - 1] = n;
    for (int i = n - 2; i >= 0; i--)
    {
        while (next.size() > 0 &&
               heights[next.top()] >= heights[i])
        {
            next.pop();
        }

        if (next.size() > 0)
        {
            nextSmaller[i] = next.top();
        }
        else
        {
            nextSmaller[i] = n;
        }

        if (next.size() == 0 ||
            heights[next.top()] < heights[i])
            next.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans,
                  (nextSmaller[i] - prevSmaller[i] - 1) * heights[i]);
    }

    return ans;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    vector<int> arr(m, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                arr[j]++;
            }
            else
            {
                arr[j] = 0;
            }
        }

        ans = max(ans,
                  largestRectangleArea(arr));
    }

    return ans;
}