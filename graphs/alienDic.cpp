// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

void DFS(char node, unordered_map<char, vector<char>> &g, unordered_set<char> &visited, stack<char> &st)
{
    visited.insert(node);
    if (g.find(node) != g.end())
    {
        for (auto it : g[node])
        {
            if (visited.find(it) == visited.end())
            {
                DFS(it, g, visited, st);
            }
        }
    }

    st.push(node);
}
string findOrder(string dict[], int N, int K)
{
    // code here
    unordered_map<char, vector<char>> g;

    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];

        int p = 0, q = 0;
        while (p < s1.size() && q < s2.size())
        {

            if (s1[p] != s2[q])
            {
                g[s1[p]].push_back(s2[q]);
                break;
            }
            p++;
            q++;
        }
    }
    stack<char> st;
    string ans = "";
    unordered_set<char> visited;
    for (auto it : g)
    {
        if (visited.find(it.first) == visited.end())
        {
            DFS(it.first, g, visited, st);
        }
    }
    while (st.size() > 0)
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}