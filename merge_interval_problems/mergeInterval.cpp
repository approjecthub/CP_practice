// https://leetcode.com/problems/merge-intervals/
// https://docs.google.com/document/d/1rUyk-1pioNOZvh9gp7lPbDbm0G6cEKP0QlyrlrvVQhY/edit#

    static bool comp(vector<int>& x,  vector<int>& y){
        return x[0]<y[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++){
            int ansSize = ans.size();
            if(ans[ansSize-1][1]>= intervals[i][0]){
                ans[ansSize-1][1] = max(ans[ansSize-1][1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }