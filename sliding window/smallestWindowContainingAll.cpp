// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1/

string smallestWindow(string s, string p)
{
    // Your code here
    unordered_map<char, int> umap;
    int ns = s.size(), np = p.size();
    int k = np, strt = 0;
    for (int i = 0; i < np; i++)
    {
        umap[p[i]]++;
    }

    string ans = "-1";
    int ansSize = INT_MAX;
    for (int i = 0; i < ns; i++)
    {
        if (umap.find(s[i]) != umap.end())
        {
            if (umap[s[i]] > 0)
                k--;
            umap[s[i]]--;
        }

        if (k == 0)
        {
            // shrink the window
            while (strt < i)
            {
                if (umap.find(s[strt]) != umap.end() && umap[s[strt]] + 1 > 0)
                {
                    break;
                }
                else if (umap.find(s[strt]) != umap.end())
                {
                    umap[s[strt]]++;
                }
                strt++;
            }
            if (i - strt + 1 < ansSize)
            {
                ans = s.substr(strt, i - strt + 1);
                ansSize = i - strt + 1;
            }
            if (umap.find(s[strt]) != umap.end())
            {
                umap[s[strt]]++;
                strt++;
                k++;
            }
        }
    }

    return ans;
}