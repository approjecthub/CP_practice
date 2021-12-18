//https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cnt=0;
        vector<vector<int>> mat(n, vector<int> (n, 0));
        int endCol=n-1, strtCol=0, strtRow=0, endRow=n-1;
        
        while(cnt<n*n){
            
            for(int i=strtCol; i<=endCol; i++){
                mat[strtRow][i] = ++cnt;
            }
            
            strtRow++;
            for(int i=strtRow; i<=endRow; i++){
                mat[i][endCol] = ++cnt;
            }
            endCol--;
            
            for(int i=endCol; i>=strtCol;i--){
                mat[endRow][i] = ++cnt; 
            }
            endRow--;
            
            for(int i=endRow; i>=strtRow; i--){
                mat[i][strtCol]= ++cnt;
            }
            strtCol++;
            
        }
        
        return mat;
        
    }
};
