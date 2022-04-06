//https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return nums;
        
        unordered_map<int,int> umap;
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            if(umap[nums[i]]==0 && umap[nums[i]-1]==0 && umap[nums[i]+1]==0){
                umap[nums[i]]=-1;
            }
            else {
                if(umap[nums[i]+1]==-1){
                    umap[nums[i]+1]=1;
                }
                if(umap[nums[i]-1]==-1){
                    umap[nums[i]-1]=1;    
                }
                umap[nums[i]]=1;
            }
        }
        for(auto it:umap){
            if(it.second==-1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

//naive approach was to use sorting which TC: O(nlogn)