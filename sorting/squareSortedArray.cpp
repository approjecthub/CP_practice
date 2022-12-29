//https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int maxElement = INT_MIN;
        for(auto it: nums){
            maxElement = max(maxElement, abs(it));
        }
        vector<int> aux(maxElement+1, 0);
        for(auto it: nums){
            aux[abs(it)]++;
        }
        vector<int> ans;
        for(int i=0; i<=maxElement; i++){
            int count=0;
            while(count<aux[i]){
                ans.push_back(i*i);
                count++;
            }
        }
        return ans;
    }
};