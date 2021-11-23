//https://leetcode.com/problems/path-with-minimum-effort/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        set<pair<int, pair<int, int>>>s;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,  vector<int>(m,INT_MAX));
        vector<int> rd = {0,0,1,-1};
        vector<int> cd = {1,-1,0,0};
        
        dist[0][0]=0;
        s.insert({dist[0][0], {0,0}});
        
        while(!s.empty()){
            auto node = s.begin();
            int row = node->second.first;
            int col = node->second.second;
            s.erase(node);
            
            for(int i=0;i<4;i++){
                int fr = row+rd[i];
                int fc = col+cd[i];
                
                if(fr>=0 && fc>=0 && fc<m && fr<n){
                    int val = max(dist[row][col], abs(heights[row][col]-heights[fr][fc]));
                    if(val<dist[fr][fc]){
                        auto f = s.find({dist[fr][fc], {fr, fc}});
                        if(f!=s.end()){
                            s.erase(f);
                        }
                        dist[fr][fc] = val;
                        s.insert({dist[fr][fc], {fr, fc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};
