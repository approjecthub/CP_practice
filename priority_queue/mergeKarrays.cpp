// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1/

class Comapre
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    // code here
    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comapre> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push({i, arr[i][0]});
    }
    vector<int> pos(k, 0);

    while (pq.size() > 0)
    {
        pair<int, int> top = pq.top();
        pq.pop();
        pos[top.first]++;
        ans.push_back(top.second);
        if (pos[top.first] < k)
        {
            pq.push({top.first, arr[top.first][pos[top.first]]});
        }
    }

    return ans;
}