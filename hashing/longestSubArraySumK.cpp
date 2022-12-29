// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1/#

int lenOfLongSubarr(int A[], int N, int K)
{
    // Complete the function
    unordered_map<int, int> umap;
    int temp = 0, ans = 0;
    for (int i = 0; i < N; i++)
    {
        temp += A[i];
        if (umap.find(temp) == umap.end())
        {
            // cout<<i<<" , "<<temp<<endl;
            umap[temp] = i;
        }

        if (umap.find(temp - K) != umap.end())
        {
            // cout<<i<<" , "<<(temp-K)<<" , "<<umap[temp - K]<<endl;
            ans = max(ans, i - umap[temp - K]);
        }
        if (temp == K)
        {
            ans = max(ans, i + 1);
        }
    }
    return ans;
}