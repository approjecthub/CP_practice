//https://leetcode.com/problems/snakes-and-ladders/


class Solution {
public:
    bool checkVisit(vector<vector<int>> &visit, int i, int j, int n){
        return (i>=n|| i<0||j>=n || j<0 || visit[i][j] >0);
    }
    pair<int, int> getRowCol(int i, int n){
        int row,col;
        int div = i/n, rem = i%n;
        row = n-div-1;
        if(div%2==0){
            col = rem;
        }
        else{
            col = n-rem-1;
        }
        return {row, col};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>> visit (n, vector<int>(n, 0));
        
        int src = 0, dest=(n*n)-1;
        queue<pair<int,int>> q;
        q.push({src, 0});
        pair<int, int>p = getRowCol(src, n);
        visit[p.first][p.second] = 1;
        int ans = INT_MAX;
        
        while(!q.empty()){
            pair<int, int> front = q.front();
            
            if(front.first ==(n*n)-1){
                ans = min(ans, front.second);
            }
            q.pop();
            for(int i=front.first+1; i<=front.first+6 && i<(n*n); i++){
                p = getRowCol(i, n);
                int dst = i;
                if(board[p.first][p.second]!=-1){
                    dst = board[p.first][p.second]-1;
                    p = getRowCol(dst, n);
                }
                if(!checkVisit(visit, p.first,p.second,n)){
                    visit[p.first][p.second] = 1;
                    q.push({dst, front.second+1});
                }
                
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
