//https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        queue<int> q;
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0; i< nums.size();i++){
            q.push(nums[i]);
            if(dq.size()==0){
                dq.push_back(nums[i]);
            } 
            else{
                while(dq.size()>0 && dq.back()<nums[i]){
                    dq.pop_back();
                }
                dq.push_back(nums[i]);
            }
            
            if(q.size()==k){
                ans.push_back(dq.front());
                if(dq.front()==q.front()){
                    q.pop();
                    dq.pop_front();
                }
                else{
                    q.pop();
                }
            }
        }
        
        return ans;
    }
};