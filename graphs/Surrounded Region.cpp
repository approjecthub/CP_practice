//https://leetcode.com/problems/surrounded-regions/
class Solution {
public:
    
    void dfs(vector<vector<char>>& board, int i, int j,int m,int n){
        if(i>=0 && j>=0 && i<=n-1 && j<=m-1 && board[i][j]=='O'){
            board[i][j]='o';
            dfs(board,i+1,j,m,n);
            dfs(board,i-1,j,m,n);
            dfs(board,i,j+1,m,n);
            dfs(board,i,j-1,m,n);
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int m = board[0].size();
        int n = board.size();
        
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && (i==0|| j==0|| i==n-1 || j==m-1)){
                    dfs(board, i, j, m, n);
                }
            }
        }
        
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O'){
                   board[i][j] = 'X'; 
                }
                else if(board[i][j]=='o'){
                   board[i][j] = 'O'; 
                }
            }
        }
    }
};
