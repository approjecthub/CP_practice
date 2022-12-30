// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/

int minSteps(string s, string t)
{
    vector<int> sarr(26, 0);
    vector<int> tarr(26, 0);

    for (char c : s)
    {
        sarr[c - 'a']++;
    }
    for (char c : t)
    {
        tarr[c - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (sarr[i] > tarr[i] > 0)
        {
            sarr[i] -= tarr[i];
        }
        else
        {
            sarr[i] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        ans += sarr[i];
    }

    return ans;
}