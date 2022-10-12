// https://practice.geeksforgeeks.org/problems/word-ladder/1

// TC: O(26 * N * N * W), N=> length of word, W=> no .of words
int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    // Code here
    queue<pair<string, int>> que;
    que.push({startWord, 1});
    unordered_set<string> uset(wordList.begin(), wordList.end());

    while (que.size() > 0)
    {
        auto topP = que.front();
        string node = topP.first;
        int level = topP.second;
        que.pop();

        if (node == targetWord)
            return level;

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

    return 0;
}