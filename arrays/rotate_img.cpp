// https://leetcode.com/problems/rotate-image/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void inSolve(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i <= n / 2; i++) {

            for (int j = i; j < n - 1 - i; j++) {
                int temp1 = matrix[i][j], temp2 = matrix[i][j];
                // 1st rotation
                temp2 = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp1;
                temp1 = temp2;

                // 2nd rotation
                temp2 = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = temp1;
                temp1 = temp2;

                // 3rd rotation
                temp2 = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = temp1;
                temp1 = temp2;

                // 4th rotation
                temp2 = matrix[i][j];
                matrix[i][j] = temp1;
                temp1 = temp2;
            }
        }
    }
    void outSolve(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][n - 1 - i] = matrix[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = ans[i][j];
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) { inSolve(matrix); }
};