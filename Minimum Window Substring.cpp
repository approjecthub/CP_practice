//https://leetcode.com/problems/minimum-window-substring/

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int ns = s.length();
        int nt = t.length();

        if (ns < nt)
        {
            return "";
        }
        if (ns == nt)
        {
            string ans = s;
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            if (s == t)
            {
                return ans;
            }
            return "";
        }

        string ans = "";

        unordered_map<char, int> umapt, umaps;

        for (int i = 0; i < nt; i++)
        {
            if (umapt.find(t[i]) == umapt.end())
            {
                umapt[t[i]] = 1;
            }
            else
            {
                umapt[t[i]]++;
            }
        }

        int cnt = 0, len = INT_MAX, strt_idx = 0;

        for (int i = 0; i < ns; i++)
        {
            if (umapt.find(s[i]) != umapt.end())
            {
                if (umaps.find(s[i]) == umaps.end())
                {
                    umaps[s[i]] = 1;
                }
                else
                {
                    umaps[s[i]]++;
                }
                if (umapt[s[i]] == umaps[s[i]])
                {
                    cnt += umapt[s[i]];
                }
            }

            if (cnt == nt)
            {
                while (strt_idx < i)
                {
                    if (umapt.find(s[strt_idx]) != umapt.end())
                    {
                        umaps[s[strt_idx]]--;
                        if (umaps[s[strt_idx]] < umapt[s[strt_idx]])
                        {
                            cnt -= umapt[s[strt_idx]];
                            break;
                        }
                    }
                    strt_idx++;
                }

                if (len > i - strt_idx)
                {
                    ans = s.substr(strt_idx, i - strt_idx + 1);
                    len = i - strt_idx;
                }

                strt_idx++;
            }
        }
        return ans;
    }
};
