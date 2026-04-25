// https://leetcode.com/problems/range-sum-query-2d-immutable/

#include <bits/stdc++.h>
using namespace std;

/*
 * 2D prefix sums (psMat is 1-based; mat is 0-based).
 *
 *   psMat[i][j] = sum of mat[0..i-1][0..j-1]  (rectangle from origin to cell (i-1,j-1))
 *
 * Toy matrix mat (2x3)          psMat (padding row 0 / col 0 are zeros)
 *   1  2  3                         0  0  0  0
 *   4  5  6                         0  1  3  6
 *                                   0  5 12 21
 *
 * Recurrence (inclusion–exclusion on overlapping rectangles):
 *   psMat[i][j] = mat[i-1][j-1] + psMat[i][j-1] + psMat[i-1][j] - psMat[i-1][j-1]
 *                 \___________/   \_________/   \__________/   \____________/
 *                 this cell       strip left      strip above    counted twice
 *
 * Query sum of the shaded region (row1,col1)..(row2,col2):
 *
 *        col1    col2
 *         |      |
 *   row1 -+------+----  take full prefix to (row2,col2),
 *         |//////|        then subtract the strips strictly above row1
 *         |//////|        and strictly left of col1; the top-left overlap
 *   row2 -+------+----  was removed twice, so add it back once.
 *         ^
 *
 *   sumRegion = psMat[r2+1][c2+1] - psMat[r1][c2+1] - psMat[r2+1][c1] + psMat[r1][c1]
 */
class NumMatrix {
    private:
        vector<vector<int>> mat;
        vector<vector<int>> psMat;
    
    public:
        NumMatrix(vector<vector<int>>& matrix) {
            mat = matrix;
            psMat = vector<vector<int>>(mat.size() + 1,
                                        vector<int>(mat[0].size() + 1, 0));
    
            for (int i = 1; i <= mat.size(); i++) {
                for (int j = 1; j <= mat[0].size(); j++) {
                    psMat[i][j] = mat[i - 1][j - 1] + psMat[i][j - 1] +
                                  psMat[i - 1][j] - psMat[i - 1][j - 1];
                }
            }
        }
    
        int sumRegion(int row1, int col1, int row2, int col2) {
    
            return psMat[row2 + 1][col2 + 1] - psMat[row2 + 1][col1] -
                   psMat[row1][col2 + 1] + psMat[row1][col1];
        }
    };