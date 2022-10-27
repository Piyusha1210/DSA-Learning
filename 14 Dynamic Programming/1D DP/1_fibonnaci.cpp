#include <bits/stdc++.h>
using namespace std;

int memo_fib(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];

    dp[n] = memo_fib(n - 1, dp) + memo_fib(n - 2, dp);
    return dp[n];
}

int memo_tab(int n)
{
    if (n <= 1)
        return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << memo_fib(n, dp) << endl;
    cout << memo_tab(n) << endl;
    return 0;
}