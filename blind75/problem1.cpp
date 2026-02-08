// https://leetcode.com/problems/two-sum/description/
// Topics: Two Sum, HashMap, Two Pointer, Sorting

class Solution {
public:
    static bool compSort(pair<int, int> &p1, pair<int, int> &p2){
        return p1.first<p2.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        vector<pair<int, int>> arr;

        for(int l=0; l<=j; l++){
            arr.push_back({nums[l], l});
        }
        sort(arr.begin(), arr.end(), compSort);

        while(i<j){
            if(arr[i].first+arr[j].first==target){
                return {arr[i].second, arr[j].second};
            }
            else if(arr[i].first+arr[j].first<target){
                i++;
            }
            else{
                j--;
            }
        }

        return {-1, -1};
    }
};