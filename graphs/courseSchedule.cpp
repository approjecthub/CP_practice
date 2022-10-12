// https://leetcode.com/problems/course-schedule/

//topological sorting
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> g[numCourses];
    vector<int> indegree(numCourses, 0);
    for (auto it : prerequisites)
    {
        g[it[1]].push_back(it[0]);
        indegree[it[0]]++;
    }

    queue<int> que;

    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            que.push(i);
        }
    }

    if (que.size() == 0)
        return false;

    while (que.size() > 0)
    {
        int node = que.front();
        que.pop();

        for (auto it : g[node])
        {
            if (--indegree[it] == 0)
            {
                que.push(it);
            }
        }
    }

    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] > 0)
        {
            return false;
        }
    }

    return true;
}