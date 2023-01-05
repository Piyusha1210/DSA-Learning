#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i = 1; i < n; i++)
        {
            if(arr[i] > ans.back())
                ans.push_back(arr[i]);
            else
            {
                auto idx = lower_bound(ans.begin(), ans.end(), arr[i]);
                ans[idx-ans.begin()] = arr[i];
            }
        }
        return ans.size();
    }
};