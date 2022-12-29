// https://leetcode.com/problems/word-break/

class Solution
{
public:
    bool solve(string s, unordered_set<string> &uset, unordered_map<string, bool> &umap)
    {
        int n = s.size();
        if (n == 0)
            return true;
        else
        {
            if (umap.find(s) != umap.end())
            {
                return umap[s];
            }
            if (uset.find(s) != uset.end())
            {
                umap[s] = true;
                return true;
            }

            bool ans = false;
            for (int i = 0; i < n; i++)
            {
                string ss = s.substr(0, i + 1);
                // cout<<ss<<endl;
                if (uset.find(ss) != uset.end())
                {
                    ans = ans || solve(s.substr(i + 1, n - i - 1), uset, umap);
                }
            }
            umap[s] = ans;
            return ans;
        }
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> uset;
        unordered_map<string, bool> umap;
        for (auto it : wordDict)
        {
            uset.insert(it);
        }
        return solve(s, uset, umap);
    }
};

//https://leetcode.com/problems/word-break/discuss/43814/C%2B%2B-Dynamic-Programming-simple-and-fast-solution-(4ms)-with-optimization