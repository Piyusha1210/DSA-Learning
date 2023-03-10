#include <bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;

// https://cses.fi/problemset/task/1633/
int memoisation(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    dp[n] = 0;
    for (int i = 1; i <= 6 && n >= i; i++)
    {
        dp[n] = (dp[n] % M + memoisation(n - i, dp) % M) % M;
    }
    dp[n] %= M;
    return dp[n];
}

int tabulation(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= 6 && i - j >= 0; j++)
        {
            dp[i] = (dp[i] + dp[i - j]) % M;
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    // cout << memoisation(n, dp);
    cout << tabulation(n);
    return 0;
}