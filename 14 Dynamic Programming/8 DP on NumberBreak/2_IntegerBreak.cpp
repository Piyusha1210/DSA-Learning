#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/integer-break/?envType=study-plan&id=dynamic-programming-i

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
     
        for(int i = 2; i <= n; i++)
        {
            int maxi = 1;
            for(int ind = 1; ind < i; ind++)
            {
                int temp = max(ind * (i-ind), ind * dp[i-ind]);
                maxi = max(maxi, temp);
            }
            dp[i] = maxi;
        }
        return dp[n];
    }
};