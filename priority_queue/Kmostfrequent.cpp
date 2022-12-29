// https://leetcode.com/problems/top-k-frequent-words/

class Compare
{
public:
    bool operator()(pair<string, int> &a, pair<string, int> &b)
    {

        if (a.second != b.second)
        {
            return a.second < b.second;
        }
        else
        {
            return a.first > b.first;
        }
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> umap;
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
        for (auto it : words)
        {
            umap[it]++;
        }

        for (auto it : umap)
        {
            pq.push({it.first, it.second});
        }

        vector<string> ans;
        while (k > 0)
        {
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return ans;
    }
};

// ###################### sol 2#######################
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         int n = nums.size(), ufs = 0;
//         unordered_map<int, int> umap;
//         for(auto it: nums){
//             umap[it]++;
//             ufs = max(ufs, umap[it]);
//         }
        
//         vector<vector<int>> fmap (ufs+1,vector<int>());
        
//         for(auto it: umap){
//             fmap[it.second].push_back(it.first);
//         }
//         vector<int> ans;
//         for(int i=ufs; i>=1; i--){
//             int ts = fmap[i].size();
//             while (ts>0){
//                 ans.push_back(fmap[i][ts-1]);
//                 ts--;
//                 k--;
//                 if(k==0) return ans;
//             }
//         }
//         return ans;
//     }
// };