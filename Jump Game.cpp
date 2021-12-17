//https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();       
        if(n<=1) return true;
        
        int steps = 0;
        
        for(int i=0; i<n && i<=steps; i++){
            steps = max(steps, i+nums[i]);
            
            if (steps>= n-1){
                return true;
            }
        }
        
        return false;
    }
};
