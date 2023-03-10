#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size(),  M = 1e9+7;
        int noOfPairs = 0;
        long long ans = 0;
        sort(ranges.begin(), ranges.end());
        for (int i = 1; i < n; i++)
        {
            if(ranges[i][0] <= ranges[i-1][1])
                ranges[i][1] = max(ranges[i][1], ranges[i-1][1]);
            else
                noOfPairs++;
        }
        noOfPairs++;
        // cout<<noOfPairs;
        ans = 2;
        for(int i = 1; i < noOfPairs; i++)
        {
            ans = (ans * 2) % M;
        }
        ans %= M;
        return ans;
    }
};