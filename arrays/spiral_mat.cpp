// https://leetcode.com/problems/spiral-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse right
        for (int col = left; col <= right; col++)
            ans.push_back(matrix[top][col]);
        top++;

        // Traverse down
        for (int row = top; row <= bottom; row++)
            ans.push_back(matrix[row][right]);
        right--;

        // Traverse left (if rows remain)
        if (top <= bottom) {
            for (int col = right; col >= left; col--)
                ans.push_back(matrix[bottom][col]);
            bottom--;
        }

        // Traverse up (if columns remain)
        if (left <= right) {
            for (int row = bottom; row >= top; row--)
                ans.push_back(matrix[row][left]);
            left++;
        }
    }
    return ans;
}
};