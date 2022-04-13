//https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size(), ufs = 0;
        unordered_map<int, int> umap;
        for(auto it: nums){
            umap[it]++;
            ufs = max(ufs, umap[it]);
        }
        
        vector<vector<int>> fmap (ufs+1,vector<int>());
        
        for(auto it: umap){
            fmap[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i=ufs; i>=1; i--){
            int ts = fmap[i].size();
            while (ts>0){
                ans.push_back(fmap[i][ts-1]);
                ts--;
                k--;
                if(k==0) return ans;
            }
        }
        return ans;
    }
};