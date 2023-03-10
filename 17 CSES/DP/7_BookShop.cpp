#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define M 1000000007
#define pb push_back
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int n, x;
vector<vector<int>> dp;

int memoisation(int idx, int x, vector<int> &h, vector<int> &s)
{
    if (idx < 0 || x == 0)
        return 0;

    if (dp[idx][x] != -1)
        return dp[idx][x];

    int nottake = memoisation(idx - 1, x, h, s);
    int take = 0;
    if (h[idx] <= x)
    {
        take = memoisation(idx - 1, x - h[idx], h, s) + s[idx];
    }
    dp[idx][x] = max(take, nottake);
    return dp[idx][x];
}

int tabulation(int n, int W, vector<int> &wt, vector<int> &val)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    if (wt[0] <= W)
        dp[0][wt[0]] = val[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int notpick = dp[i - 1][j];
            int pick = 0;
            if (wt[i] <= j)
                pick = dp[i - 1][j - wt[i]] + val[i];
            dp[i][j] = max(pick, notpick);
        }
    }
    return dp[n - 1][W];
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> h, s;
    // dp.resize(n, vector<int>(x + 1, -1));
    int t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        h.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        s.push_back(t);
    }

    // cout << memoisation(n - 1, x, h, s);
    cout<<tabulation(n, x, h, s);
    return;
}

int32_t main()
{
    fast int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}