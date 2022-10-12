// https://practice.geeksforgeeks.org/problems/word-ladder-ii/1

void DFS(string node, string targetWord, int level,
         unordered_set<string> &uset, vector<string> &path, vector<vector<string>> &ans)
{
    if (level == 0 && node == targetWord)
    {
        ans.push_back(path);
        return;
    }
    else if (level == 0)
    {
        return;
    }

    auto it1 = uset.find(node);
    uset.erase(it1);
    for (int i = 0; i < node.size(); i++)
    {
        char currCh = node[i];
        for (int j = 0; j < 26; j++)
        {
            char ch = 'a' + j;
            if (currCh != ch)
            {
                node[i] = ch;
                auto it = uset.find(node);
                if (it != uset.end())
                {
                    path.push_back(node);
                    DFS(node, targetWord, level - 1, uset, path, ans);
                    path.pop_back();
                }
            }
        }
        node[i] = currCh;
    }
    uset.insert(node);
}
vector<vector<string>> findSequences(string startWord, string targetWord, vector<string> &wordList)
{
    queue<pair<string, int>> que;
    que.push({startWord, 0});
    unordered_set<string> uset(wordList.begin(), wordList.end());
    unordered_set<string> uset2(wordList.begin(), wordList.end());
    uset2.insert(startWord);

    int finalLevel = 0;
    while (que.size() > 0)
    {
        auto topP = que.front();
        string node = topP.first;
        int level = topP.second;
        que.pop();

        if (node == targetWord)
        {
            finalLevel = level;
            break;
        };

        for (int i = 0; i < node.size(); i++)
        {
            char currCh = node[i];
            for (int j = 0; j < 26; j++)
            {
                char ch = 'a' + j;
                if (currCh != ch)
                {
                    node[i] = ch;
                    auto it = uset.find(node);
                    if (it != uset.end())
                    {
                        que.push({node, level + 1});
                        uset.erase(it);
                    }
                }
            }
            node[i] = currCh;
        }
    }

    vector<vector<string>> ans;
    vector<string> path;
    path.push_back(startWord);
    DFS(startWord, targetWord, finalLevel, uset2, path, ans);
    return ans;
}