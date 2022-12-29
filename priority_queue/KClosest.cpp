// https://leetcode.com/problems/k-closest-points-to-origin/
//  https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/23800866#overview

class Compare
{
public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        int sqrtA = (a[0] * a[0]) + (a[1] * a[1]);
        int sqrtB = (b[0] * b[0]) + (b[1] * b[1]);
        return sqrtA < sqrtB;
    }
};
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push(points[i]);
        }

        for (int i = k; i < points.size(); i++)
        {
            int dis1 = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            vector<int> pTop = pq.top();
            int dis2 = (pTop[0] * pTop[0]) + (pTop[1] * pTop[1]);
            if (dis2 > dis1)
            {
                pq.pop();
                pq.push(points[i]);
            }
        }
        vector<vector<int>> ans;
        while (pq.size() > 0)
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};