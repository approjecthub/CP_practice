//https://www.geeksforgeeks.org/construct-binary-palindrome-by-repeated-appending-and-trimming/

void dfs(int node, vector<int> g[], vector<bool> &isVisited)
{
    isVisited[node] = true;
    for (int i = 0; i < g[node].size(); i++)
    {
        if (!isVisited[g[node][i]])
            dfs(g[node][i], g, isVisited);
    }
}
string binaryPalindrome(int n, int k)
{
    // Complete the function
    vector<int> arr(n, 0);
    vector<int> g[k];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i % k;
    }

    for (int i = 0; i < n / 2; i++)
    {
        g[arr[i]].push_back(arr[n - i - 1]);
        g[arr[n - i - 1]].push_back(arr[i]);
    }

    vector<bool> isVisited(k, false);
    string ans = "";
    dfs(0, g, isVisited);
    for (int i = 0; i < n; i++)
    {
        if (isVisited[arr[i]])
        {
            ans += "1";
        }
        else
        {
            ans += "0";
        }
    }
    return ans;
}