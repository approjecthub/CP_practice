//  https://practice.geeksforgeeks.org/problems/circle-of-strings4530/1

unordered_map<char, vector<char>> g;
unordered_map<char, bool> isVisited;
unordered_map<char, int> in;

void DFS(char node)
{
    isVisited[node] = true;
    for (auto it : g[node])
    {
        if (!isVisited[it])
            DFS(it);
    }
}
bool isConnected()
{
    for (auto it : g)
    {
        if (g[it.first].size() > 0)
        {
            DFS(it.first);
            break;
        }
    }

    for (auto it : g)
    {
        if (!isVisited[it.first] && g[it.first].size() > 0)
        {
            return false;
        }
    }
    return true;
}
bool isEuler()
{
    // 1. check connectivity
    if (!isConnected())
        return false;

    // 2. check whether all vertex have indegree== outdegree
    for (auto it : g)
    {
        if (in[it.first] != g[it.first].size())
        {
            return false;
        }
    }
    return true;
}
int isCircle(int N, vector<string> A)
{
    // code here

    for (auto it : A)
    {
        int len = it.size();
        isVisited[it[0]] = false;
        g[it[0]].push_back(it[len - 1]);
        in[it[len - 1]]++;
    }

    return isEuler();
}