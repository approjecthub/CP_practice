// https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1/

vector<int> countDistinct(int A[], int n, int k)
{
    // code here.
    unordered_map<int, int> umap;
    int strt = 0, mapSize = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        umap[A[i]]++;
        if (umap[A[i]] == 1)
            mapSize++;

        if (i - k == strt)
        {
            umap[A[strt]]--;
            if (umap[A[strt]] == 0)
                mapSize--;
            strt++;
        }

        if (i >= k - 1)
        {
            ans.push_back(mapSize);
        }
    }
    return ans;
}