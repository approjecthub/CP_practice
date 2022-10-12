//https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

bool isValid(int i, int j, int N)
{
    return i >= 1 && j >= 1 && i <= N && j <= N;
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    // Code here
    queue<vector<int>> que;
    vector<vector<int>> isVisited(N + 1, vector<int>(N + 1, 0));

    // let's reverse the knight's & target's positions, as total effort remains the same
    // pos[0] = column && pos[1] = row
    int temp = KnightPos[0];
    KnightPos[0] = KnightPos[1];
    KnightPos[1] = temp;

    temp = TargetPos[0];
    TargetPos[0] = TargetPos[1];
    TargetPos[1] = temp;

    que.push({TargetPos[0], TargetPos[1], 0}); //{row, col, level}
    isVisited[TargetPos[0]][TargetPos[1]] = 1;

    vector<int> rowOffset = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> colOffset = {1, 2, 2, 1, -1, -2, -2, -1};
    while (que.size() > 0)
    {
        vector<int> top = que.front();
        que.pop();
        int i = top[0], j = top[1], level = top[2];
        if (i == KnightPos[0] && j == KnightPos[1])
        {
            return level;
        }

        for (int l = 0; l < 8; l++)
        {
            int row = i + rowOffset[l];
            int col = j + colOffset[l];

            if (isValid(row, col, N) && isVisited[row][col] == 0)
            {
                isVisited[row][col] = 1;
                que.push({row, col, level + 1});
            }
        }
    }

    return -1;
}