// https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        set<pair<int, pair<int, int>>> st;
        unordered_set<string> visited;
        unordered_map<string, int> dis;
        int ans = 0, n = points.size();

        for (int i = 0; i < n; i++)
        {
            string point = to_string(points[i][0]) + to_string(points[i][1]);
            dis[point] = INT_MAX;
        }
        int src = 0;
        string srcName = to_string(points[src][0]) + to_string(points[src][1]);
        st.insert({0, {points[src][0], points[src][1]}});
        dis[srcName] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            auto top = st.begin();
            pair<int, int> node = top->second;
            int wt = top->first;
            int x1 = node.first;
            int y1 = node.second;
            string nodeName = to_string(x1) + to_string(y1);
            visited.insert(nodeName);
            st.erase(top);

            for (int l = 0; l < n; l++)
            {
                int x2 = points[l][0];
                int y2 = points[l][1];
                string adjNode = to_string(x2) + to_string(y2);
                int adjNodeDis = abs(x2 - x1) + abs(y2 - y1);

                if (visited.find(adjNode) == visited.end() && adjNodeDis < dis[adjNode])
                {
                    auto ele = st.find({dis[adjNode], {x2, y2}});
                    if (ele != st.end())
                    {
                        st.erase(ele);
                    }
                    st.insert({adjNodeDis, {x2, y2}});
                    dis[adjNode] = adjNodeDis;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            string point = to_string(points[i][0]) + to_string(points[i][1]);
            ans += dis[point];
        }

        return ans;
    }
};