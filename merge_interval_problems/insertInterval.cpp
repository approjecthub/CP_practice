// https://leetcode.com/problems/insert-interval/

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = 0, r = intervals.size()-1, idx=-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(intervals[mid][0]>= newInterval[0]){
                idx = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        cout<<idx<<endl;
        if(idx==-1){
            intervals.push_back(newInterval);
        }
        else{
            intervals.insert(intervals.begin()+idx, newInterval);
        }


        return merge(intervals);
    }