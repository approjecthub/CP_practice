// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

// my incorrect soln
int solve(string S, int i, int j, char expr)
{
    if (i > j)
        return 0;
    else if (i == j)
    {
        return S[i] == expr ? 1 : 0;
    }

    int totalT = 0, totalF = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int leftT = solve(S, i, k - 1, 'T'), leftF = solve(S, i, k - 1, 'F');
        int rightT = solve(S, k + 1, j, 'T'), rightF = solve(S, k + 1, j, 'F');
        int costT = 0, costF = 0;

        if (S[k] == '&')
        {
            costT += leftT * rightT;
            costF += (leftF * rightF) + (leftF * rightT) + (leftT * rightF);
        }
        else if (S[k] == '|')
        {
            costT += (leftT * rightT) + (leftF * rightT) + (leftT * rightF);
            costF += (leftF * rightF);
        }
        else if (S[k] == '^')
        {
            costT += (leftF * rightT) + (leftT * rightF);
            costF += (leftT * rightT) + (leftF * rightF);
        }
        totalT += costT;
        totalF += costF;
    }

    return expr == 'T' ? totalT : totalF;
}
int countWays(int N, string S)
{
    // code here
    // return solve(S,0, N-1, 'T');
    int mod = 1003;
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, 0)));

    for (int i = 0; i < N; i++)
    {
        dp[i][i][0] = S[i] == 'F' ? 1 : 0;
        dp[i][i][1] = S[i] == 'T' ? 1 : 0;
    }
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int totalT = 0, totalF = 0;
            for (int k = i + 1; k <= j - 1; k += 2)
            {
                int leftT = dp[i][k - 1][1], leftF = dp[i][k - 1][0];
                int rightT = dp[k + 1][j][1], rightF = dp[k + 1][j][0];
                int costT = 0, costF = 0;

                if (S[k] == '&')
                {
                    costT = (leftT * rightT) % mod;
                    costF = (((leftF * rightF) % mod) + ((leftF * rightT) % mod) + ((leftT * rightF) % mod)) % mod;
                }
                else if (S[k] == '|')
                {
                    costT = (((leftT * rightT) % mod) + ((leftF * rightT) % mod) + ((leftT * rightF) % mod)) % mod;
                    costF = (leftF * rightF) % mod;
                }
                else if (S[k] == '^')
                {
                    costT = (((leftF * rightT) % mod) + ((leftT * rightF) % mod)) % mod;
                    costF = (((leftT * rightT) % mod) + ((leftF * rightF) % mod) % mod);
                }
                totalT = (totalT + costT) % mod;
                totalF = (totalF + costF) % mod;
            }
            dp[i][j][0] = totalF;
            dp[i][j][1] = totalT;
        }
    }

    return dp[0][N - 1][1];
}