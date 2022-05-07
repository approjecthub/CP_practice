//https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0,j=0, temp=0;
        unordered_map<int, int> umap;
        umap[0] = 1;
        for(int i=0; i<nums.size(); i++){
            temp+= nums[i];
            ans+=umap[temp-k];//here if any key is not present then it return 0         
            umap[temp] += 1;
        }
        
        return ans;
    }
};
