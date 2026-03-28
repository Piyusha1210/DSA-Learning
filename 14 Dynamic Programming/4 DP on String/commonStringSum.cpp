class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int sumS1 = ASCIISumOfString(s1);
        int sumS2 = ASCIISumOfString(s2);

        int commonStringASCIISum = CommonStringASCIISum(s1, s2);
        int ans = (sumS1 + sumS2) - 2 * commonStringASCIISum;
        return ans;
    }

    int ASCIISumOfString(string &s) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++) {
            sum += s[i];
        }
        return sum;
    }

    int CommonStringASCIISum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp = vector<vector<int>>(n+1, vector<int>(m+1));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s1[i] == s2[j]) {
                    dp[i+1][j+1] = dp[i][j] + s1[i];
                }
                else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[n][m];
    }

    string maxCommonSubSequence(string &s1, string &s2, vector<vector<int>> &dp) {
        int n = s1.size(), m = s2.size();
        int i = n, j = m;
        string s = "";
        while(i > 0 && j > 0) {
            if(dp[i][j] == dp[i-1][j]) {
                i--;
            }
            else if(dp[i][j] == dp[i][j-1]) {
                j--;
            }
            else {
                i--;
                j--;
                s.push_back(s1[i]);
            }
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
        return s;
    }

    int minimumASCIISUM(string &s, string &s1, string &s2) {
        map<char, pair<int, int>> mp;
        for(int i = 0; i < s.size(); i++) {
            // if(mp.find(s[i]) == mp.end())
            //     mp[s[i]] = {1, 1};
            // else {
                mp[s[i]].first++;
                mp[s[i]].second++;
            // }
        }

        int ans = 0;
        for(int i = 0; i < s1.size(); i++) {
            if(mp[s1[i]].first > 0)
                mp[s1[i]].first--;
            else 
                ans += s1[i];
        }
        cout << ans << " ";

        for(int i = 0; i < s2.size(); i++) {
            if(mp[s2[i]].second > 0)
                mp[s2[i]].second--;
            else
                ans += s2[i];
        }

        cout << ans << " ";

        return ans;
    }
};

/*
sea
eat
  e a t
s 0 0 0
e 1 1 1
a 1 2 2

  l e e t
d 0 0 0 0
e 0 1 1 1
l 1 1 1 1
e 1 2 2 2
t 1 2 2 3
e 1 2 2 3
*/


