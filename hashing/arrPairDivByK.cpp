// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

//https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/discuss/709212/Short-C%2B%2B-Solution-explained-with-comments
bool canArrange(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> umap(k, 0);

    for (int i = 0; i < n; i++)
    {
        int rem = (arr[i] % k + k) % k;
        umap[rem]++;
    }
    for (int i = 0; i < k; i++)
    {
        // cout<<umap[i]<<endl;
        if (i == 0 && umap[i] % 2 == 0)
            continue;
        else if (i > 0 && umap[i] == umap[k - i])
            continue;
        else
        {
            return false;
        }
    }
    return true;
}