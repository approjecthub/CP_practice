//https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=-1, col=-1,i,j,mid,m=matrix[0].size(),n=matrix.size();
        
        //base case
        if(m==0 or n==0) return false;

        i=0;
        j=n;
        int i1=0,j1=m,mid1;
        while(i<j){
            mid = (i+j)/2;
            if(matrix[mid][0]>target && matrix[mid][m-1]>target){
                j = mid;
            }
            else if(matrix[mid][0]<target && matrix[mid][m-1]<target){
                i=mid+1;
            }
            else{

                while(i1<j1){
                    mid1 = (i1+j1)/2;
                    
                    if(matrix[mid][mid1]>target){
                        j1 = mid1;
                    }
                    else if(matrix[mid][mid1]<target){
                        i1=mid1+1;
                    }
                    else{
                        return true;
                    }

                }
                return false;
            }
        }
        return false;
        
    }
};
