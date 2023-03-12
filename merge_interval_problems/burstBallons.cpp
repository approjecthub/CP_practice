// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

    static bool customComp(vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), customComp);
        int i =0, n = points.size(), ans=0;

        while(i<n){
            int j = i+1, end=points[i][1];

            while(j<n && points[j][0]<= end){
                end = min(end, points[j][1]);
                j++;
            }

            ans++;
            // i = max(i+1,j);
            i=j;
        }
        
        return ans;
    }