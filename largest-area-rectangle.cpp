//https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ps;
        ps.assign(n, -1);
        vector<int> ns;
        ns.assign(n, n);
        
        stack<int> st1;
        for(int i=0; i<n;i++){
            while(st1.size()>0){
                int k= st1.top();
                if(heights[k]>=heights[i]){
                    st1.pop();
                }
                else{
                    break;
                }
            }
            if(st1.size()>0){
                ps[i] = st1.top();
            }
            st1.push(i);
        }
        stack<int> st2;
        for(int i=n-1; i>=0;i--){
            while(st2.size()>0){
                int k = st2.top();
                if(heights[k]>=heights[i]){
                    st2.pop();
                }
                else{
                    break;
                }
            }
            if(st2.size()>0){
                ns[i] = st2.top();
            }
            st2.push(i);
            
        }
        
        int maxArea = 0;
        for(int i=0; i<n;i++){
            int temparea = (ns[i]-ps[i]-1)*heights[i];
            
            if(temparea>maxArea){
                maxArea = temparea;
            }
        }
        
        return maxArea;
    }
};