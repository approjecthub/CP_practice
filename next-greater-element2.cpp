//https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> op;
        op.assign(n,-1);
        stack<int> st;
        
        for(int i =0; i<2*n; i++){
            int j = i%n;
            
            while(st.size()>0){
                int k = st.top();
                if(nums[k]<nums[j]){
                    if(op[k]==-1 )
                    op[k] = nums[j];
                    
                    st.pop();
                }
                else{
                    break;
                }
            
            }
            st.push(j);
        }
        
        return op;
    }
};