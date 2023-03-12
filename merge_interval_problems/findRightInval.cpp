// https://leetcode.com/problems/find-right-interval/

    static bool customComp(vector<int> &a, vector<int>& b){
        return a[0]<b[0];
    }
    int findIdx(vector<vector<int>>& intervals, int i){
        int r = intervals.size()-1, idx=-1,
        l=0, ele=intervals[i][1];

        while(l<=r){
            int mid = l + (r-l)/2;

            if(intervals[mid][0] >= ele){
                idx = intervals[mid][2];
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return idx;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for(int i=0; i<n; i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end(), customComp);
        vector<int> ans(n,-1);

        for(int i=0; i<n; i++){
            int idx = findIdx(intervals, i);
            ans[intervals[i][2]] = idx;
        }

        return ans;
    }