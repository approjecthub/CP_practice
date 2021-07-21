//https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    bool static compare(vector<int> a, vector<int> b){
        if(a[1]<b[1]){
            return true;
        }
        else if(a[1]==b[1]){
            return a[0]>b[0];
        }
        else{
            return false;
        }
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int start = intervals[0][0];
        int end = intervals[0][1];
        int ans = 0;
        for(int i = 1; i<intervals.size(); i++){
            if(end>intervals[i][0]){
                ans++;
            }
            else{
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        return ans;
    }
};
