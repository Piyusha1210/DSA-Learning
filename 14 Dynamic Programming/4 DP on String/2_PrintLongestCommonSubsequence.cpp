/* Uncomplete ??? */
// https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-all-lcs-sequences

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void tabulation(string s, string t, vector<vector<int>> &dp)
    {
        int n = s.size(), m = t.size();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i] == t[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    void fndString(int i, int j, string s, string t, string str, vector<vector<int>> &dp, vector<string> &ans)
    {
        if (i == 0 || j == 0)
        {
            ans.push_back(str);
            return;
        }

        while (i > 0 && j > 0)
        {
            if (dp[i][j] == dp[i - 1][j - 1] + 1)
            {
                str.push_back(s[i - 1]);
                i--;
                j--;
            }
            else
            {
                if (dp[i - 1][j] == dp[i][j - 1])
                {
                    fndString(i - 1, j, s, t, str, dp, ans);
                    fndString(i, j - 1, s, t, str, dp, ans);
                    return;
                }
                else if (dp[i - 1][j] > dp[i][j - 1])
                {
                    i--;
                }
                else
                {
                    j--;
                }
            }
        }
        ans.push_back(str);
        return;
    }

    vector<string> all_longest_common_subsequences(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        tabulation(s, t, dp);
        vector<string> ans;
        string str;
        fndString(n, m, s, t, str, dp, ans);
        return ans;
    }
};
