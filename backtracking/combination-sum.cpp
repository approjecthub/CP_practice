// https://leetcode.com/problems/combination-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int>& candidates, vector<int>& temp, int idx, int target ){
        int n = candidates.size();

        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(idx == n){
            return;
        }


        solve(ans, candidates, temp, idx + 1, target);
        if(candidates[idx] <= target){
        temp.push_back(candidates[idx]);
        solve(ans, candidates, temp, idx, target - candidates[idx]);
        temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, candidates, temp, 0, target);
        return ans;
    }
};