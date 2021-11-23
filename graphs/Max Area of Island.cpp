//https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int bfs(vector<vector<int>>& grid, int r, int c, int n, int m){
        queue<pair<int,int>> q;
        int count=1;
        
        q.push({r,c});
        grid[r][c]=-1;
        
        vector<int> rd = {0, 0, 1, -1};
        vector<int> cd = {1, -1, 0, 0};
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int l=0;l<4;l++){
                int fi = i+rd[l];
                int fj = j+cd[l];
                
                if(fi>=0 && fj>=0 && fi<n && fj<m){
                    if(grid[fi][fj] == 1){
                        count++;
                        grid[fi][fj] = -1;
                        q.push({fi,fj});
                    }
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                if(grid[i][j]==1){
                     ans = max(ans, bfs( grid, i, j,n, m));
                }
            }
        }
        
        return ans;
    }
};
