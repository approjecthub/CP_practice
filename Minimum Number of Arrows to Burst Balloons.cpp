class Solution {
public:
    bool static comparefn(vector<int> a, vector<int> b)
    {
        
        if(a[0]<b[0])
            return true;
        else if(a[0]==b[0]){
            return a[1]<=b[1];
        }
        else{
            return false;
        }
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int n = points.size();
        sort(points.begin(), points.end(), comparefn);
        int ans = 0;
        
        for (int i=0; i<n;){
            int start = points[i][0];
            int end = points[i][1];
            
            int j = i+1;
            for(; j<n; j++){
                if(points[j][0] >= start &&  points[j][0] <= end){
                   start = max(start,points[j][0] );
                    end = min(end, points[j][1]);
                }
                else{
                    break;
                }
            }
            i = max(j, i+1);
            ans++;
            
        }
        
        return ans;
    }
};
