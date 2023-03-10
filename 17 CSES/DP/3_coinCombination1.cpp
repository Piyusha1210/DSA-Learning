#include <bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;

int memoisation(int x, vector<int> &coins, vector<int> &dp)
{
    if (x == 0)
        return 1;

    if (dp[x] != -1)
        return dp[x];

    dp[x] = 0;
    for (int i = 0; i < coins.size() && coins[i] <= x; i++)
    {
        dp[x] = (dp[x] % M + memoisation(x - coins[i], coins, dp) % M) % M;
    }
    // cout << x << " " << dp[x] << endl;
    return dp[x];
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
    vector<int> dp(x + 1, -1);
    cout << memoisation(x, coins, dp);

    return 0;
}