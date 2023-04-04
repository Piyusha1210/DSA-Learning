#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/contest/weekly-contest-336/problems/count-the-number-of-beautiful-subarrays/

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        map<int, int> mp;
        int curr = 0;
        long long ans = 0;
        mp[0] = 1;
        for(auto i: nums)
        {
            curr ^= i;
            if(mp.find(curr) != mp.end())
            {
                ans += mp[curr];
                mp[curr]++;
            }
                
            else
            {
                mp[curr] = 1;
            }
                
        }
        return ans;
    }
};