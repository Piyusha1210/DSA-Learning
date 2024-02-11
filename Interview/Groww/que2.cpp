#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));

    if (v[0][0] = 1)
        dp[0][0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (v[i][0] == 1)
        {
            dp[i][0] = dp[i - 1][0] + 1;
        }
    }

    for (int i = 1; i < m; i++)
    {
        if (v[0][i] == 1)
        {
            dp[0][i] = dp[0][i - 1] + 1;
        }
    }

    cout << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][j] == 1)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - 2 * dp[i - 1][j - 1] + 1;
                cout << dp[i][j] << " ";
            }
        }
        cout << endl;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans += dp[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}

// 101
// 110
// 110

// 101
// 220
// 340