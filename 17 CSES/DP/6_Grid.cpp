#include <bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;

int memoisation(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &dp)
{
    if(i < 0 || j < 0)
        return 0;

    if(grid[i][j] == '*')
    {
        dp[i][j] = 0;
        return dp[i][j];
    }

    if(i == 0 && j == 0)
    {
        dp[i][j] = 1;
        return dp[i][j];
    }
        
    if(dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = (memoisation(i-1, j, grid, dp) + memoisation(i, j-1, grid, dp)) % M;
    return dp[i][j];
}

int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << memoisation(n-1, n-1, grid, dp);
    return 0;
}