// https://leetcode.com/problems/largest-rectangle-in-histogram/

////////////////////////////////////////////////////////

int largestRectangleArea(vector<int> &heights)
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

////// ////////////////////////////////////////
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> ps;
        ps.assign(n, -1);
        vector<int> ns;
        ns.assign(n, n);

        stack<int> st1;
        for (int i = 0; i < n; i++)
        {
            while (st1.size() > 0)
            {
                int k = st1.top();
                if (heights[k] >= heights[i])
                {
                    st1.pop();
                }
                else
                {
                    break;
                }
            }
            if (st1.size() > 0)
            {
                ps[i] = st1.top();
            }
            st1.push(i);
        }
        stack<int> st2;
        for (int i = n - 1; i >= 0; i--)
        {
            while (st2.size() > 0)
            {
                int k = st2.top();
                if (heights[k] >= heights[i])
                {
                    st2.pop();
                }
                else
                {
                    break;
                }
            }
            if (st2.size() > 0)
            {
                ns[i] = st2.top();
            }
            st2.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int temparea = (ns[i] - ps[i] - 1) * heights[i];

            if (temparea > maxArea)
            {
                maxArea = temparea;
            }
        }

        return maxArea;
    }
};