#include <bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;

int memoisation(int n, int x, vector<int> &coins, vector<vector<int>> &dp)
{
    if (x == 0)
        return 0;
    if (n < 0)
        return INT_MAX;

    if (dp[n][x] != -1)
        return dp[n][x];

    int notpick = memoisation(n - 1, x, coins, dp);
    int pick = INT_MAX;
    if (coins[n] <= x)
    {
        pick = memoisation(n, x - coins[n], coins, dp);
        if (pick != INT_MAX)
            pick++;
    }
    return dp[n][x] = min(pick, notpick);
}

int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    int ans = memoisation(n - 1, x, coins, dp);
    if (ans == INT_MAX)
        ans = -1;
    cout << ans;
    return 0;
}
